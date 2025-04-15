#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
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

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

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
	logger = iniciar_logger();
	log_info(logger, "El valor de CLAVE es: %s", valor);
	config_destroy(config);

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config

	/* ---------------- LEER DE CONSOLA ---------------- */

	// Leer los loggers
	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

    while (!string_is_empty(leido)) {
        log_info(logger, "%s", leido);
        free(leido);
        leido = readline("> ");
    }

    free(leido); // liberamos la línea vacía también

	// ¡No te olvides de liberar las lineas antes de regresar!
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	  log_destroy(logger);
}
