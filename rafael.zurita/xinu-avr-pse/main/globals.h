
void pulsador_global(void);
void pulsadores(void);
void brazo(void);
void led(void);
void motor_stop(void);
int motor_izq(void);
int motor_der(void);
void motor_init(void);

extern int encendido;
extern int dia;
extern int estado;

#define MOTOR_DER_PIN 4
#define MOTOR_IZQ_PIN 5

#define APAGADO 0
#define START 1
#define MOVIENDO 2
#define ESPERANDO 3
#define ESPERANDO_1_DIA 4

