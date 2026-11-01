
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)
#define BUTTON_NODE DT_ALIAS(sw0)

static const struct gpio_dt_spec led =
    GPIO_DT_SPEC_GET(LED_NODE, gpios);

static const struct gpio_dt_spec button =
    GPIO_DT_SPEC_GET(BUTTON_NODE, gpios);

int main(void)
{
    if (!gpio_is_ready_dt(&led) ||   !gpio_is_ready_dt(&button)) {
        return 0;
    }

    int ret;

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        return 0;
    }

    ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
    if (ret < 0) {
        return 0;
    }

    while (1) {
        int pressed = gpio_pin_get_dt(&button);

        if (pressed < 0) {
            return 0;
        }

        gpio_pin_set_dt(&led, pressed);

        k_msleep(20);
    }

    return 0;
}
