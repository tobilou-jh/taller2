#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    float notas[5][3];
    float promedio[5];
    float promedioa[3];
    float cALTAes = 0;
    float cALTAasig = 0;
    float cBAJAes = 10;
    float cBAJAasig = 10;
    float abrobar = 0;
    float altaEstudiante[5], bajaEstudiante[5];
    float altaAsignatura[3], bajaAsignatura[3];
    int aprobadosPorAsignatura[3] = {0, 0, 0};
    int reprobadosPorAsignatura[3] = {0, 0, 0};
    int opc = 0;
    int opc2 = 0;
    int opc3 = 0;
    int opc4 = 0;
    int opc5 = 1;
    char estudiantes[5][30];
    char asig[3][30];
    int cont = 0;
    int cont2 = 0;
    int len = 0;
    int validacion = 0;
    int val = 0;
    char val2 = 0;

    do {
        printf("Ingrese un opcion: \n");
        printf("1. Ingresar estudiantes: \n");
        printf("2. Ingrese la asignaturas: \n");
        printf("3. Ingresar notas: \n");
        printf("4. Mostrar promedios: \n");
        printf("5. Mostrar notas: \n");
        printf("6. Mostrar nota mas alta y mas baja\n");
        printf("7. Mostrar aprobados y reprobados\n");
        printf("8. Salir\n");
        printf(">> ");
        fflush(stdin);
        val=scanf("%d", &opc);
        if(val != 1){
            printf("Dato invalido\n");
            opc=0;       
        }
        if(opc==1){
            validacion++;
        }
        if(opc==2){
            validacion++;
        }


        switch (opc) {
        case 1:
            do {
                printf("Ingrese el nombre del estudiante: \n");
                fflush(stdin);
                fgets(estudiantes[cont], 30, stdin);
                len = strlen(estudiantes[cont]) - 1;
                estudiantes[cont][len] = '\0';
                cont++;
                printf("Desea ingresar otro estudiante? (1: Si, 2: No): \n");
                do{
                    fflush(stdin);
                    val=scanf("%d", &opc2);
                    if(val != 1){
                        printf("Dato invalido\n");
                        opc2=0;       
                    }
                    if (opc2 != 1 && opc2 != 2) {
                        printf("Opcion invalida. Ingrese nuevamente: \n");
                    }
                }while (opc2 != 1 && opc2 != 2);
                if (cont >= 5) {
                    printf("Limite de estudiantes alcanzado.\n");
                    opc2 = 2;
                }
            } while (opc2 == 1);
            break;

        case 2:
            opc2 = 1;
            cont2 = 0;
            do {
                printf("Ingrese el nombre de la asignatura: \n");
                fflush(stdin);
                fgets(asig[cont2], 30, stdin);
                len = strlen(asig[cont2]) - 1;
                if (len > 0 && asig[cont2][len] == '\n') {
                    asig[cont2][len] = '\0';
                }
                cont2++;
                printf("Desea ingresar otra asignatura? (1: Si, 2: No): \n");
                do{
                    fflush(stdin);
                    val=scanf("%d", &opc2);
                    if(val != 1){
                        printf("Dato invalido\n");
                        opc2=0;       
                    }
                    if (opc2 != 1 && opc2 != 2) {
                        printf("Opcion invalida. Ingrese nuevamente: \n");
                    }
                }while (opc2 != 1 && opc2 != 2);
                if (cont2 >= 3) {
                    printf("Limite de asignaturas alcanzado.\n");
                    opc2 = 2;
                }
            } while (opc2 == 1);
            break;

        case 3:
            if (validacion < 2) {
                printf("Primero debe ingresar estudiantes y asignaturas.\n");
                break;
            }else{
                do {
                    printf("Ingrese las notas de los alumnos:\n");
                    printf("#\t\tNombre\n");
                    for (int i = 0; i < cont; i++) {
                        printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                    }
                    printf("Ingrese el numero del estudiante: \n");
                    do{
                        fflush(stdin);
                        val=scanf("%d", &opc3);
                        if(val != 1){
                            printf("Dato invalido\n");
                            opc3=0;       
                        }
                        if(opc3<1 || opc3>cont){
                            printf("Opcion invalida. Ingrese nuevamente: \n");
                        }
                    }while(opc3<1 || opc3>cont);
                    opc3--;
                    printf("#\t\tAsignatura\n");
                    fflush(stdin);
                    for (int i = 0; i < cont2; i++) {
                        printf("%d\t\t%s\n", i + 1, asig[i]);
                    }
                    printf("Ingrese el numero de la asignatura: \n");
                    do{
                        fflush(stdin);
                        val=scanf("%d", &opc4);
                        if(val != 1){
                            printf("Dato invalido\n");
                            opc4=0;       
                        }
                        if(opc4<1 || opc4>cont2){
                            printf("Opcion invalida. Ingrese nuevamente: \n");
                        }
                    }while(opc4<1 || opc4>cont2);
                    opc4--;
                    printf("Ingrese la nota a ingresar: \n");
                    do {
                        fflush(stdin);
                        val=scanf("%f", &notas[opc3][opc4]);
                        if(val != 1){
                            printf("Dato invalido\n");
                            notas[opc3][opc4]=0;       
                        }
                        if (notas[opc3][opc4] < 0 || notas[opc3][opc4] > 10) {
                            printf("Nota invalida. Ingrese nuevamente: ");
                        }
                    } while (notas[opc3][opc4] < 0 || notas[opc3][opc4] > 10);
                    validacion++;
    
                    printf("Desea ingresar otra nota? (1: Si, 2: No): \n");
                    do{
                        fflush(stdin);
                        val=scanf("%d", &opc5);
                        if(val != 1){
                            printf("Dato invalido\n");
                            opc5=0;       
                        }
                        if (opc5 != 1 && opc5 != 2) {
                            printf("Opcion invalida. Ingrese nuevamente: \n");
                        }
                    } while (opc5 != 1 && opc5 != 2);
                } while (opc5 == 1);
            }
            
            break;

        case 4:
            if (validacion < (cont*cont2)) {
                printf("Primero debe ingresar estudiantes, asignaturas e ingresar todas las notas de los estudiantes asignados.\n");
                break;
            }else{
                printf("Promedios de los alumnos:\n");
                printf("#\t\tNombre\n");
                for (int i = 0; i < cont; i++) {
                    printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                }

                for (int i = 0; i < cont; i++) {
                    promedio[i] = 0;
                    for (int j = 0; j < cont2; j++) {
                        promedio[i] += notas[i][j];
                        if (notas[i][j] > altaAsignatura[j]) {
                            altaAsignatura[j] = notas[i][j];
                        }
                        if (notas[i][j] < bajaAsignatura[j]) {
                            bajaAsignatura[j] = notas[i][j];
                        }
                    }
                    promedio[i] /= cont2;
                    printf("%s %d: %.2f\n", estudiantes[i], i + 1, promedio[i]);
                }
                printf("Promedios de las asignaturas:\n");
                for (int j = 0; j < cont2; j++) {
                    promedioa[j] = 0;
                    for (int i = 0; i < cont; i++) {
                        promedioa[j] += notas[i][j];
                    }
                    promedioa[j] /= cont;
                    printf("%s: %.2f\n", asig[j], promedioa[j]);
                }

            }
            
            break;

        case 5:
            if (validacion < (cont*cont2)) {
                printf("Primero debe ingresar estudiantes, asignaturas e ingresar todas las notas de los estudiantes asignados.\n");
                break;
            }else{
                printf("Notas de los alumnos:\n");
                printf("#\t\tNombre\n");
                for (int i = 0; i < cont; i++) {
                    printf("%d\t\t%s\n", i + 1, estudiantes[i]);
                }

                for (int i = 0; i < cont; i++) {
                    for (int j = 0; j < cont2; j++) {
                        printf("El estudiante %s en la materia %s obtuvo una nota de: %.2f\n", estudiantes[i], asig[j], notas[i][j]);
                    }
                }
            }
            
            break;

        case 6:
            if (validacion < (cont*cont2)) {
                printf("Primero debe ingresar estudiantes, asignaturas e ingresar todas las notas de los estudiantes asignados.\n");
                break;
            }else{
                printf("Notas mas altas y mas bajas por estudiante:\n");
                for (int i = 0; i < cont; i++) {
                    float CAltaes = -1, CBajaes = 11;
                    for (int j = 0; j < cont2; j++) {
                        if (notas[i][j] > CAltaes) {
                            CAltaes = notas[i][j];
                        }
                        if (notas[i][j] < CBajaes) {
                            CBajaes = notas[i][j];
                        }
                    }
                    printf("%s su nota mas alta es: %.2f, su nota mas baja es: %.2f\n", estudiantes[i], CAltaes, CBajaes);
                }

                printf("\nNotas mas altas y mas bajas por asignatura:\n");
                for (int j = 0; j < cont2; j++) {
                    float CAltaasig = -1, CBajaasig = 11;
                    for (int i = 0; i < cont; i++) {
                        if (notas[i][j] > CAltaasig) {
                            CAltaasig = notas[i][j];
                        }
                        if (notas[i][j] < CBajaasig) {
                            CBajaasig = notas[i][j];
                        }
                    }
                    printf("%s la nota mas alta es: %.2f, la mas baja: %.2f\n", asig[j], CAltaasig, CBajaasig);
                }
            }

            
            break;
        case 7:
            if (validacion < (cont*cont2)) {
                printf("Primero debe ingresar estudiantes, asignaturas e ingresar todas las notas de los estudiantes asignados.\n");
                break;
            }else{
                printf("Aprobados y Reprobados:\n");
                for (int j = 0; j < cont2; j++) {
                    for (int i = 0; i < cont; i++) {
                        if (notas[i][j] >= 6) {
                            aprobadosPorAsignatura[j]++;
                        } else {
                            reprobadosPorAsignatura[j]++;
                        }
                    }
                    printf("En la asignatura %s hay %d aprobados y %d reprobados\n", asig[j], aprobadosPorAsignatura[j], reprobadosPorAsignatura[j]);
                }
            }
            
            
            break;
        case 8:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion no valida. Intente nuevamente.\n");
            break;
        }
    } while (opc != 8);

    return 0;
}
