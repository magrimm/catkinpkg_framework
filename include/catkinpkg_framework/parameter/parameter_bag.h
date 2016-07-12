//
// Created by marius on 16.04.16.
//

#ifndef CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
#define CATKINPKG_FRAMEWORK_PARAMETER_BAG_H

#include <string>

namespace framework {

struct ParameterBag {
  // Parameter specific to parameter bag
  std::string node_name;

  std::string sub_rostopic_img;
  int queue_size_sub_img;

  std::string sub_rostopic_cam;
  int queue_size_sub_cam;

  std::string pub_rostopic_objects;
  int queue_size_pub_objects;

  std::string pub_rostopic_img;
  int queue_size_pub_img;
};

} // namespace framework

#endif //CATKINPKG_FRAMEWORK_PARAMETER_BAG_H
