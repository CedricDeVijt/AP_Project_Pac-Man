#ifndef AP_PROJECT_PAC_MAN_CAMERA_H
#define AP_PROJECT_PAC_MAN_CAMERA_H
#include <tuple>

/**
 * @class Camera
 * @brief Models how the positions of the entities in coordinate system [-1, 1] will be mapped on the screen.
 */
class Camera {
public:
    /**
     * @brief Converts normalized coordinates to pixel coordinates
     * @param position The normalized position
     * @return The pixel positions on the X and Y-axis.
     */
    static std::tuple<int, int> toPixelCoordinates(std::tuple<double, double, double, double> position);

private:
    /**
     * @brief Converts normalized coordinates to pixel coordinates on the X-axis.
     * @param position The normalized position on the X-axis.
     * @return The pixel position on the X-axis.
     */
    static int toPixelX(double position);

    /**
     * @brief Converts normalized coordinates to pixel coordinates on the Y-axis.
     * @param position The normalized position on the Y-axis.
     * @return The pixel position on the Y-axis.
     */
    static int toPixelY(double position);

};

#endif // AP_PROJECT_PAC_MAN_CAMERA_H
