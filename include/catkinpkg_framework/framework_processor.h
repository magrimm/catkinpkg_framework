//
// Created by marius on 16.04.16.
//

#ifndef CATKINPKG_FRAMEWORK_FRAMEWORK_PROCESSOR_H
#define CATKINPKG_FRAMEWORK_FRAMEWORK_PROCESSOR_H

#include <image_transport/image_transport.h>
#include <ros/package.h>
#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <std_msgs/Float64.h>

#include <iostream>
#include <vector>

#include "catkinpkg_framework/parameter/parameter_bag.h"

namespace framework {

// Default values
static const std::string kDefaultImageSubTopic   = "/camX/image_raw";
static const std::string kDefaultCamSubTopic     = "/camera_info";
static const std::string kDefaultObjectsPubTopic = "detection_result";

static constexpr int kDefaultImageSubQueueSize   = 1;
static constexpr int kDefaultCamSubQueueSize     = 1;
static constexpr int kDefaultObjectsPubQueueSize = 500;

/**
 * \brief Processor which organises the subscription and publishing of the data.
 * @author Marius Grimm (mgrimm@ethz.ch)
 * @date April, 2016
 */
class FrameworkProcessor {
 public:
  /**
   * \brief The Constructor.
   * @param [in] nh Ros NodeHandle.
   * @param [in] parameter Struct storing relevant parameters for the processor
   *                       and the tree structure of parameter bags for the
   *                       individual modules.
   */
  FrameworkProcessor(const ros::NodeHandle& nh, const ParameterBag& parameter);

  /** \brief The Destructor. */
  virtual ~FrameworkProcessor();

  /**
   * \brief Callback for the image.
   * @param [in] img_msg Ros message storing the image data.
   */
  void CallbackImg(const sensor_msgs::ImageConstPtr& a_image_msg);

 private:
  /** \brief Ros NodeHandle. */
  ros::NodeHandle nh_;

  /** \brief ImageTransport for image subscription. */
  image_transport::ImageTransport it_;

  /**
   * \brief Struct storing the relevant parameters for the processor and the tree
   *        structure of parameter bags for other modules.
   */
  ParameterBag parameter_;

  /** \brief Ros Subscriber for the camera. */
  ros::Subscriber sub_cam_;

  /** \brief Image Transport Subscriber for the image. */
  image_transport::Subscriber sub_img_;

  /** \brief Ros Publisher for the objects. */
  ros::Publisher pub_objects_;

  /** \brief Image Transport Publisher for the modified image. */
  image_transport::Publisher pub_img_;
};

} // namespace framework

#endif //CATKINPKG_FRAMEWORK_FRAMEWORK_PROCESSOR_H
