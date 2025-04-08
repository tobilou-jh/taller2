#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    float notas[5][3];
    float promedio[5];
    float promedioa[3];
    float cALTAes=0;
    float cALTAasig=0;
    float cBAJAes=10;
    float cBAJAasig=10;
    float abrobar=0;
    float altaEstudiante[5], bajaEstudiante[5];
    float altaAsignatura[3], bajaAsignatura[3];
    int aprobadosPorAsignatura[3] = {0, 0, 0};
    int reprobadosPorAsignatura[3] = {0, 0, 0};

    printf("Ingrese las notas de los alumnos:\n");
    for (int i = 0; i < 5; i++) {
        printf("Alumno %d: \n", i + 1);
        altaEstudiante[i] = 0;
        bajaEstudiante[i] = 10;
        for (int j = 0; j < 3; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            if (notas[i][j] < 0 || notas[i][j] > 10) {
                printf("Nota invalida. Ingrese nuevamente: ");
                j--;
            } else {
                if (notas[i][j] > altaEstudiante[i]) {
                    altaEstudiante[i] = notas[i][j];
                }
                if (notas[i][j] < bajaEstudiante[i]) {
                    bajaEstudiante[i] = notas[i][j];
                }
                if (notas[i][j] >= 6) {
                    aprobadosPorAsignatura[j]++;
                } else {
                    reprobadosPorAsignatura[j]++;
                }
            }
        }
    }

    printf("Promedios de los alumnos:\n");
    for (int i = 0; i < 5; i++) {
        promedio[i] = (notas[i][0] + notas[i][1] + notas[i][2]) / 3;
        printf("Alumno %d: %.2f\n", i + 1, promedio[i]);
        if (promedio[i] > cALTAes) {
            cALTAes = promedio[i];
        }
        if (promedio[i] < cBAJAes) {
            cBAJAes = promedio[i];
        }
    }

    printf("Promedios de las asignaturas:\n");
    for (int j = 0; j < 3; j++) {
        promedioa[j] = 0;
        altaAsignatura[j] = 0;
        bajaAsignatura[j] = 10;
        for (int i = 0; i < 5; i++) {
            promedioa[j] += notas[i][j];
            if (notas[i][j] > altaAsignatura[j]) {
                altaAsignatura[j] = notas[i][j];
            }
            if (notas[i][j] < bajaAsignatura[j]) {
                bajaAsignatura[j] = notas[i][j];
            }
        }
        promedioa[j] /= 5;
        printf("Asignatura %d: %.2f\n", j + 1, promedioa[j]);
    }

    printf("Promedio mas alto de los alumnos: %.2f\n", cALTAes);
    printf("Promedio mas bajo de los alumnos: %.2f\n", cBAJAes);
    printf("Promedio mas alto de las asignaturas: %.2f\n", cALTAasig);
    printf("Promedio mas bajo de las asignaturas: %.2f\n", cBAJAasig);

    printf("Calificacion mas alta y baja por estudiante:\n");
    for (int i = 0; i < 5; i++) {
        printf("Alumno %d: Alta = %.2f, Baja = %.2f\n", i + 1, altaEstudiante[i], bajaEstudiante[i]);
    }

    printf("Calificacion mas alta y baja por asignatura:\n");
    for (int j = 0; j < 3; j++) {
        printf("Asignatura %d: Alta = %.2f, Baja = %.2f\n", j + 1, altaAsignatura[j], bajaAsignatura[j]);
    }

    printf("Alumnos aprobados: \n");
    for (int i = 0; i < 5; i++) {
        if (promedio[i] >= 6) {
            printf("Alumno %d: %.2f\n", i + 1, promedio[i]);
        } else {
            abrobar++;
        }
    }

    printf("Alumnos reprobados: \n");   
    for (int i = 0; i < 5; i++) {
        if (promedio[i] < 6) {
            printf("Alumno %d: %.2f\n", i + 1, promedio[i]);
        }
    }

    printf("Estudiantes aprobados y reprobados por asignatura:\n");
    for (int j = 0; j < 3; j++) {
        printf("Asignatura %d: Aprobados = %d, Reprobados = %d\n", j + 1, aprobadosPorAsignatura[j], reprobadosPorAsignatura[j]);
    }

    return 0;
}
