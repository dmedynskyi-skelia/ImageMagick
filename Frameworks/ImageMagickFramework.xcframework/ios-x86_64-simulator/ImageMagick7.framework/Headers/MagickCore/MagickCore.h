/*
  Copyright 1999-2017 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    https://www.imagemagick.org/script/license.php
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  MagickCore Application Programming Interface declarations.
*/

#ifndef MAGICKCORE_CORE_H
#define MAGICKCORE_CORE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#if !defined(MAGICKCORE_CONFIG_H)
# define MAGICKCORE_CONFIG_H
# if !defined(vms) && !defined(macintosh)
#  include "ImageMagick7/MagickCore/magick-config.h"
# else
#  include "ImageMagick7/Magick-config.h"
# endif
#if defined(_magickcore_const) && !defined(const)
# define const _magickcore_const
#endif
#if defined(_magickcore_inline) && !defined(inline)
# define inline _magickcore_inline
#endif
#if !defined(magick_restrict)
# if !defined(_magickcore_restrict)
#  define magick_restrict restrict
# else
#  define magick_restrict _magickcore_restrict
# endif
#endif
# if defined(__cplusplus) || defined(c_plusplus)
#  undef inline
# endif
#endif
#if __cplusplus > 199711L
#define register
#endif

#define MAGICKCORE_CHECK_VERSION(major,minor,micro) \
  ((MAGICKCORE_MAJOR_VERSION > (major)) || \
    ((MAGICKCORE_MAJOR_VERSION == (major)) && \
     (MAGICKCORE_MINOR_VERSION > (minor))) || \
    ((MAGICKCORE_MAJOR_VERSION == (major)) && \
     (MAGICKCORE_MINOR_VERSION == (minor)) && \
     (MAGICKCORE_MICRO_VERSION >= (micro))))

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <time.h>

#if defined(WIN32) || defined(WIN64)
#  define MAGICKCORE_WINDOWS_SUPPORT
#else
#  define MAGICKCORE_POSIX_SUPPORT
#endif 

#include "ImageMagick7/MagickCore/method-attribute.h"

#if defined(MAGICKCORE_NAMESPACE_PREFIX)
# include "ImageMagick7/MagickCore/methods.h"
#endif
#include "ImageMagick7/MagickCore/magick-type.h"
#include "ImageMagick7/MagickCore/animate.h"
#include "ImageMagick7/MagickCore/annotate.h"
#include "ImageMagick7/MagickCore/artifact.h"
#include "ImageMagick7/MagickCore/attribute.h"
#include "ImageMagick7/MagickCore/blob.h"
#include "ImageMagick7/MagickCore/cache.h"
#include "ImageMagick7/MagickCore/cache-view.h"
#include "ImageMagick7/MagickCore/channel.h"
#include "ImageMagick7/MagickCore/cipher.h"
#include "ImageMagick7/MagickCore/client.h"
#include "ImageMagick7/MagickCore/coder.h"
#include "ImageMagick7/MagickCore/color.h"
#include "ImageMagick7/MagickCore/colorspace.h"
#include "ImageMagick7/MagickCore/colormap.h"
#include "ImageMagick7/MagickCore/compare.h"
#include "ImageMagick7/MagickCore/composite.h"
#include "ImageMagick7/MagickCore/compress.h"
#include "ImageMagick7/MagickCore/configure.h"
#include "ImageMagick7/MagickCore/constitute.h"
#include "ImageMagick7/MagickCore/decorate.h"
#include "ImageMagick7/MagickCore/delegate.h"
#include "ImageMagick7/MagickCore/deprecate.h"
#include "ImageMagick7/MagickCore/display.h"
#include "ImageMagick7/MagickCore/distort.h"
#include "ImageMagick7/MagickCore/distribute-cache.h"
#include "ImageMagick7/MagickCore/draw.h"
#include "ImageMagick7/MagickCore/effect.h"
#include "ImageMagick7/MagickCore/enhance.h"
#include "ImageMagick7/MagickCore/exception.h"
#include "ImageMagick7/MagickCore/feature.h"
#include "ImageMagick7/MagickCore/fourier.h"
#include "ImageMagick7/MagickCore/fx.h"
#include "ImageMagick7/MagickCore/gem.h"
#include "ImageMagick7/MagickCore/geometry.h"
#include "ImageMagick7/MagickCore/histogram.h"
#include "ImageMagick7/MagickCore/identify.h"
#include "ImageMagick7/MagickCore/image.h"
#include "ImageMagick7/MagickCore/image-view.h"
#include "ImageMagick7/MagickCore/layer.h"
#include "ImageMagick7/MagickCore/linked-list.h"
#include "ImageMagick7/MagickCore/list.h"
#include "ImageMagick7/MagickCore/locale_.h"
#include "ImageMagick7/MagickCore/log.h"
#include "ImageMagick7/MagickCore/magic.h"
#include "ImageMagick7/MagickCore/magick.h"
#include "ImageMagick7/MagickCore/matrix.h"
#include "ImageMagick7/MagickCore/memory_.h"
#include "ImageMagick7/MagickCore/module.h"
#include "ImageMagick7/MagickCore/mime.h"
#include "ImageMagick7/MagickCore/monitor.h"
#include "ImageMagick7/MagickCore/montage.h"
#include "ImageMagick7/MagickCore/morphology.h"
#include "ImageMagick7/MagickCore/opencl.h"
#include "ImageMagick7/MagickCore/option.h"
#include "ImageMagick7/MagickCore/paint.h"
#include "ImageMagick7/MagickCore/pixel.h"
#include "ImageMagick7/MagickCore/pixel-accessor.h"
#include "ImageMagick7/MagickCore/policy.h"
#include "ImageMagick7/MagickCore/prepress.h"
#include "ImageMagick7/MagickCore/profile.h"
#include "ImageMagick7/MagickCore/property.h"
#include "ImageMagick7/MagickCore/quantize.h"
#include "ImageMagick7/MagickCore/quantum.h"
#include "ImageMagick7/MagickCore/registry.h"
#include "ImageMagick7/MagickCore/random_.h"
#include "ImageMagick7/MagickCore/resample.h"
#include "ImageMagick7/MagickCore/resize.h"
#include "ImageMagick7/MagickCore/resource_.h"
#include "ImageMagick7/MagickCore/segment.h"
#include "ImageMagick7/MagickCore/shear.h"
#include "ImageMagick7/MagickCore/signature.h"
#include "ImageMagick7/MagickCore/splay-tree.h"
#include "ImageMagick7/MagickCore/stream.h"
#include "ImageMagick7/MagickCore/statistic.h"
#include "ImageMagick7/MagickCore/string_.h"
#include "ImageMagick7/MagickCore/timer.h"
#include "ImageMagick7/MagickCore/token.h"
#include "ImageMagick7/MagickCore/transform.h"
#include "ImageMagick7/MagickCore/threshold.h"
#include "ImageMagick7/MagickCore/type.h"
#include "ImageMagick7/MagickCore/utility.h"
#include "ImageMagick7/MagickCore/version.h"
#include "ImageMagick7/MagickCore/vision.h"
#include "ImageMagick7/MagickCore/xml-tree.h"
#include "ImageMagick7/MagickCore/xwindow.h"

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
