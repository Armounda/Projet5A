/**
  ******************************************************************************
  * @file    sinus_network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Dec 13 15:26:31 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "sinus_network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_sinus_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_sinus_network_weights_array_u64[53] = {
  0x636273684739caf7U, 0x565f44ae197fe640U, 0x0U, 0xffffea75ffffeac2U,
  0xfffffa24fffffab8U, 0xffffffacffffefc8U, 0xd44U, 0xffffea33000007bdU,
  0xffffe4cc00000000U, 0xffffe3cf00000d4fU, 0x24f4211909ed1af4U, 0x19faf5f7bcef21e0U,
  0x2f4f90602d2dc03U, 0xe127d3eff1effaffU, 0x1a05e4dbebdd27fbU, 0xe41eef151224fc17U,
  0xf1f3f81cda14fe10U, 0xe3ede9e309f3e2efU, 0xfe1a1b040b0715e4U, 0x3ec0be621de01ebU,
  0xe603271e24220a23U, 0xf1fcf811c0ff2403U, 0xe51707f3e0f50c11U, 0x7fb23e8dcfaede8U,
  0x1711261400fdfbddU, 0x4042602ea11f1e7U, 0x20dc1ddb0a1d2125U, 0x161af10b37e3fa01U,
  0x30216e003e71cefU, 0xb14e5d92e091821U, 0xd8c40013d8fc1aeaU, 0xd6d820190dfed9ecU,
  0xc6dde2cad7e91fe2U, 0xc71401003e04e713U, 0x1ad606f51515e7dbU, 0xef130208fe2209dcU,
  0xdd14f3fd09e21e19U, 0xeef7f9e30fd920daU, 0xe216070029e624e9U, 0xfa14f7ddd3230d1eU,
  0xb0f080921262208U, 0x26e558dc7ff412e0U, 0x7a2fffffd27U, 0x262U,
  0xfffffe29000000f1U, 0xfffffc9dffffffddU, 0x2450000023bU, 0xf67000010a4U,
  0x24fU, 0xffffec11fffffc87U, 0xdddee01c15273bd9U, 0x7ff9dd12d7c51b0fU,
  0x1adU,
};


ai_handle g_sinus_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_sinus_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

