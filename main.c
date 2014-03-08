#include <pololu/orangutan.h>
#include <util/delay.h>

void led_avr() {
	DDRA |= 0xFF;
	DDRC |= 0x00;
	PINC = 0xFF;

	while (1) {
		PORTA = PINC;
	}
}

void led_pololu() {
	while (1) {
		green_led(0);
		delay(1000);
		green_led(1);
		delay(1000);
	}
}

void servo() {
	clear();

	const unsigned char demuxPins[] = { };
	servos_start(demuxPins, sizeof(demuxPins));

	set_servo_target(0, 1300);

	set_servo_speed(0, 0);

	while (1) {
		if (button_is_pressed(TOP_BUTTON)) {
			red_led(1);
			green_led(0);
			clear();
			print("Moving Left...");

			set_servo_target(0, 0);
			_delay_ms(400);

			set_servo_target(0, 200);
		}

		if (button_is_pressed(BOTTOM_BUTTON)) {
			red_led(0);
			green_led(1);
			clear();
			print("Moving Right...");

			set_servo_target(0, 0);
			_delay_ms(400);

			set_servo_target(0, 1800);
		}
	}
}

int main() {
	//led_pololu();
	servo();
	//led_avr();
}
