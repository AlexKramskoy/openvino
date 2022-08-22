// Copyright (C) 2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <vector>

#include "kernel_base_opencl.h"

namespace kernel_selector {

/**
 * Prior Box kernel params.
 */
struct prior_box_params : public base_params {
    prior_box_params() : base_params{KernelType::PRIOR_BOX} {}

    // operation attributes
    std::vector<float> min_size;
    std::vector<float> max_size;
    std::vector<float> density;
    std::vector<float> fixed_ratio;
    std::vector<float> fixed_size;
    bool clip;
    bool flip;
    float step;
    float offset;
    bool scale_all_sizes;
    bool min_max_aspect_ratios_order;
    std::vector<float> widths;
    std::vector<float> heights;
    float step_widths;
    float step_heights;
    bool is_clustered;
    std::vector<float> aspect_ratio;
    std::vector<float> variance;
    float reverse_image_width, reverse_image_height;
    float step_x, step_y;
    uint32_t width, height;
    uint32_t num_priors_4;
};

/**
 * Specific optional params is not defined for Prior Box v8 operation.
 */
struct prior_box_optional_params : optional_params {
    prior_box_optional_params() : optional_params{KernelType::PRIOR_BOX} {}
};

/**
 * Reference GPU kernel for the PriorBox-8 operation.
 */
class PriorBoxKernelRef : public KernelBaseOpenCL {
public:
    PriorBoxKernelRef() : KernelBaseOpenCL{"prior_box_ref"} {}

private:
    KernelsData GetKernelsData(const Params& params, const optional_params& options) const override;

    KernelsPriority GetKernelsPriority(const Params& params, const optional_params& options) const override;

    ParamsKey GetSupportedKey() const override;

    bool Validate(const Params& params, const optional_params& optionalParams) const override;

    JitConstants GetJitConstants(const prior_box_params& params) const;
};

} /* namespace kernel_selector */
