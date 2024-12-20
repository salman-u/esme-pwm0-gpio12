#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define PWM_CHIP_PATH "/sys/class/pwm/pwmchip0"
#define PWM_CHANNEL "0"
#define PERIOD_NS "100000"

void write_to_file(const char *path, const char *value) {
    int fd = open(path, O_WRONLY);
    if (fd < 0) exit(EXIT_FAILURE);
    if (write(fd, value, strlen(value)) < 0) exit(EXIT_FAILURE);
    close(fd);
}

void configure_pwm() {
    char path[256];
    snprintf(path, sizeof(path), "%s/export", PWM_CHIP_PATH);
    write_to_file(path, PWM_CHANNEL);
    snprintf(path, sizeof(path), "%s/pwm%s/period", PWM_CHIP_PATH, PWM_CHANNEL);
    write_to_file(path, PERIOD_NS);
    snprintf(path, sizeof(path), "%s/pwm%s/enable", PWM_CHIP_PATH, PWM_CHANNEL);
    write_to_file(path, "1");
}

void set_duty_cycle(int duty_cycle_percent) {
    char path[256], value[32];
    long duty_cycle_ns = atol(PERIOD_NS) * duty_cycle_percent / 100;
    snprintf(path, sizeof(path), "%s/pwm%s/duty_cycle", PWM_CHIP_PATH, PWM_CHANNEL);
    snprintf(value, sizeof(value), "%ld", duty_cycle_ns);
    write_to_file(path, value);
}

void run_pwm_cycle() {
    configure_pwm();
    while (1) {
        for (int i = 0; i <= 100; i++) {
            set_duty_cycle(i);
            usleep(1000);
        }
        for (int i = 100; i >= 0; i--) {
            set_duty_cycle(i);
            usleep(1000);
        }
    }
}

int main() {
    run_pwm_cycle();
    return 0;
}
