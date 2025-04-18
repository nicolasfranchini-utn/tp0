#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	// int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	t_log* iniciar_logger(void) {
		return log_create("src/tp0.log", "LOG TEST", true, LOG_LEVEL_INFO);
	};

	logger = iniciar_logger();

	log_info(logger, "Hola! Soy un log");

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	t_config* iniciar_config(void) {
		t_config* nuevo_config = config_create("./cliente.config");

		if (nuevo_config == NULL) {
			printf("No se pudo crear el config.\n");
			abort();
		};

		return nuevo_config;
	};

	config = iniciar_config();

	valor = config_get_string_value(config, "CLAVE");
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	// Loggeamos el valor de config
	log_info(logger, "El valor de CLAVE es: %s", valor);
	log_info(logger, "El valor de IP es: %s", ip);
	log_info(logger, "El valor de PUERTO es: %s", puerto);

	/* ---------------- LEER DE CONSOLA ---------------- */

	// Leer los loggers
	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	// conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	// paquete(conexion);

	// terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

void leer_consola(t_log* logger)
{
	char* leido = readline("> ");

	while (!string_is_empty(leido)) {
		log_info(logger, "El valor leido es: %s", leido);
		add_history(leido);
        free(leido);
		leido = readline("> ");
    }

    free(leido); // liberamos la línea vacía también
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	// char* leido;
	// t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	config_destroy(config);
	log_destroy(logger);
}
