#include <cosmodon.hpp>
#include <render/opengl.hpp>
#include "test.hpp"

int main()
{
    uint8_t i;
    cosmodon::clock timer;
    cosmodon::rate fps;

    try {
        cosmodon::number value = 0.01;
        cosmodon::vector up;

        // Prepare test camera.
        cosmodon::camera camera;

        // Start OpenGL window.
        cosmodon::opengl window(1024, 768, "Cosmodon Demo");
        window.set_camera(camera);

        // Prepare rendered objects.
        cosmodon::shape::triangle triangle;

        // Set default shaders.
        cosmodon::shader vertex(cosmodon::shader::vertex), fragment(cosmodon::shader::fragment);
        window.set_shaders(&vertex, &fragment);

        // Perform demo.
        while (true) {
            // Transform triangle.
            if (i++ <= 255) {
                triangle.rotate(value, value, value);

                i = 0;
                value += 0.01;
            }

            // Display triangle.
            window.clear(cosmodon::black);
            window.render(&triangle);
            window.display();

            // Update FPS.
            fps.tally();
            if (timer.elapsed(cosmodon::unit::millisecond) > 100) {
                timer.reset();
                window.set_window_title(std::to_string(fps.get()));
            }
        }
    }

    // Catch errors.
    catch (cosmodon::exception::base &e) {
        std::cout << e.what() << std::endl;
    }
}
