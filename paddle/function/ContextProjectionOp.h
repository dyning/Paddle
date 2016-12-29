/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include "Function.h"

namespace paddle {

/**
 * \brief   Context Projection Forward.
 *
 * \param[out]  outputs           output data.
 * \param[in]   input             input data.
 * \param[in]   weight            input weight.
 * \param[in]   sequence          input data.
 * \param[in]   context_length    consecutive rows for concatenation.
 * \param[in]   context_start     context start position.
 * \param[in]   begin_pad         begining pad position.
 * \param[in]   is_padding        whether padding 0 or not.
 *
 */
template <DeviceType Device>
void ContextProjectionForward(Tensor& output,
                              const Tensor& input,
                              const Tensor& weight,
                              const Tensor& sequence,
                              size_t context_length,
                              int context_start,
                              size_t begin_pad,
                              bool is_padding);

/**
 * \brief   Context Projection Backward.
 *
 * \param[out]  outputs           output gradient.
 * \param[in]   input             input gradient.
 * \param[in]   weight            input weight gradient.
 * \param[in]   sequence          input data.
 * \param[in]   context_length    consecutive rows for concatenation.
 * \param[in]   context_start     context start position.
 * \param[in]   begin_pad         begining pad position.
 * \param[in]   is_padding        whether padding 0 or not.
 *
 */
template <DeviceType Device>
void ContextProjectionBackward(Tensor& out_grad,
                               Tensor& in_grad,
                               Tensor& w_grad,
                               const Tensor& sequence,
                               size_t context_length,
                               int context_start,
                               size_t begin_pad,
                               bool is_padding,
                               size_t total_pad);

template <DeviceType Device>
void ContextProjectionBackwardData(Tensor& out_grad,
                                   Tensor& in_grad,
                                   const Tensor& sequence,
                                   size_t context_length,
                                   int context_start);

template <DeviceType Device>
void ContextProjectionBackwardWeight(Tensor& out_grad,
                                     Tensor& w_grad,
                                     const Tensor& sequence,
                                     size_t context_length,
                                     int context_start,
                                     size_t total_pad,
                                     size_t begin_pad);

}  // namespace paddle
