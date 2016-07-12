//
// Created by marius on 16.04.16.
//

#ifndef CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
#define CATKINPKG_FRAMEWORK_PARAMETER_BAG_H

#include <string>

namespace framework {

/**
 * \brief Struct to store all necessary parameters for the project with
 *        substructure of parameter bags for other modules.
 * @author Marius Grimm (marius.grimm93@web.de)
 * @date April, 2016
 */
struct ParameterBag {
  /** Node name of the tracking module. */
  std::string node_name;

  /** Subscribed rostopic for the image. */
  std::string sub_rostopic_img;

  /** Queue size for the image rostopic subscriber. */
  int queue_size_sub_img;

  /** Subscribed rostopic for the camera info. */
  std::string sub_rostopic_cam;

  /** Queue size for the camera info rostopic subscriber. */
  int queue_size_sub_cam;

  /** Published rostopic for the objects. */
  std::string pub_rostopic_objects;

  /** Queue size for the object rostopic publisher. */
  int queue_size_pub_objects;

  /** Published rostopic for the image. */
  std::string pub_rostopic_img;

  /** Queue size for the image rostopic publisher. */
  int queue_size_pub_img;
};

} // namespace framework

#endif //CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
