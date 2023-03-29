/*************************************************************************
 * Copyright (C) [2022] by Cambricon, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *************************************************************************/
#include "kernels/kernel_wrapper/wrapper.h"

mluOpStatus_t MLUOP_WIN_API mluOpRoiAlignBackward(
    mluOpHandle_t handle, const float spatial_scale, const int sampling_ratio,
    const bool aligned, const mluOpTensorDescriptor_t grads_desc,
    const void *grads, const mluOpTensorDescriptor_t boxes_desc,
    const void *boxes, const mluOpTensorDescriptor_t grads_image_desc,
    void *grads_image) {
  RoiAlignBackwardWrapper wrapper;
  mluOpStatus_t ret =
      wrapper.invoke(handle, spatial_scale, sampling_ratio, aligned, grads_desc,
                     grads, boxes_desc, boxes, grads_image_desc, grads_image);
  return ret;
}

mluOpStatus_t MLUOP_WIN_API mluOpRoiAlignBackward_v2(
    mluOpHandle_t handle, const mluOpTensorDescriptor_t grads_desc,
    const void *grads, const mluOpTensorDescriptor_t boxes_desc,
    const void *boxes, const mluOpTensorDescriptor_t argmax_x_desc,
    const void *argmax_x, const mluOpTensorDescriptor_t argmax_y_desc,
    const void *argmax_y, const float spatial_scale, const int sampling_ratio,
    const bool aligned, const int pool_mode,
    const mluOpTensorDescriptor_t grads_image_desc, void *grads_image) {
  RoiAlignBackwardV2Wrapper wrapper;
  mluOpStatus_t ret = wrapper.invoke(
      handle, grads_desc, grads, boxes_desc, boxes, argmax_x_desc, argmax_x,
      argmax_y_desc, argmax_y, spatial_scale, sampling_ratio, aligned,
      pool_mode, grads_image_desc, grads_image);
  return ret;
}
