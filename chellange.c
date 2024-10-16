#include <stdio.h>
#include <string.h>

struct motor
{
    float volts;
    float amps;
    char merek[20];
};

struct mobil
{
    char type[20];
    struct motor motor;
};

typedef struct motor motor;
typedef struct mobil mobil;

int main()
{
    // Membuat objek motor
    motor m1;
    motor *pm1;

    m1.volts = 220;
    m1.amps = 5;
    strcpy(m1.merek, "hyundai");

    pm1 = &m1;

    // Membuat objek mobil dan mengisi datanya
    mobil car1;
    strcpy(car1.type, "SUV");
    car1.motor = m1;

    // Menampilkan informasi motor
    printf("Voltage: %f\n", pm1->volts);
    printf("Current: %f\n", pm1->amps);
    printf("Merek: %s\n", pm1->merek);

    // Menampilkan informasi mobil
    printf("\nMobil Type: %s\n", car1.type);
    printf("Mobil Motor Voltage: %f\n", car1.motor.volts);
    printf("Mobil Motor Current: %f\n", car1.motor.amps);
    printf("Mobil Motor Merek: %s\n", car1.motor.merek);

    return 0;
}
