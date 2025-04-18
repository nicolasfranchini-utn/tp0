#include "client.h"

int conexion;
char* ip;
char* puerto;
char* valor;

t_log* logger;
t_config* config;

t_log* iniciar_logger(void) {
	logger = log_create("src/tp0.log", "LOG TEST", true, LOG_LEVEL_INFO);
	log_info(logger, "Hola! Soy un log");
	return logger;
};

t_config* iniciar_config(void) {
	t_config* nuevo_config = config_create("./cliente.config");

	if (nuevo_config == NULL) {
		printf("No se pudo crear el config.\n");
		abort();
	};

	return nuevo_config;
};

void leer_consola(t_log* logger) {
	char* leido = readline("> ");

	while (!string_is_empty(leido)) {
		log_info(logger, "El valor leido es: %s", leido);
		add_history(leido);
		enviar_mensaje(("Mensaje enviado desde el cliente: %s", leido), conexion);
        free(leido);
		leido = readline("> ");
    }

    free(leido);
}

void paquete(int conexion) {
	char* leido = readline("> ");;
	t_paquete* paquete;

	paquete = crear_paquete();

	while (!string_is_empty(leido)) {
		agregar_a_paquete(paquete, leido, string_length(leido) + 1);
        free(leido);
		leido = readline("> ");
    }

	enviar_paquete(paquete, conexion);

	eliminar_paquete(paquete);
}

void terminar_programa(int conexion, t_log* logger, t_config* config) {
	liberar_conexion(conexion);
	config_destroy(config);
	log_destroy(logger);
}

int main(void) {

	iniciar_logger();
	config = iniciar_config();

	valor 	= config_get_string_value(config, "CLAVE");
	ip 		= config_get_string_value(config, "IP");
	puerto 	= config_get_string_value(config, "PUERTO");

	log_info(logger, "El valor de CLAVE es: %s", valor);
	log_info(logger, "El valor de IP es: %s", ip);
	log_info(logger, "El valor de PUERTO es: %s", puerto);

	conexion = crear_conexion(ip, puerto);

	enviar_mensaje(("La clave es: %s", valor), conexion);

	paquete(conexion);

	// leer_consola(logger);

	terminar_programa(conexion, logger, config);
}