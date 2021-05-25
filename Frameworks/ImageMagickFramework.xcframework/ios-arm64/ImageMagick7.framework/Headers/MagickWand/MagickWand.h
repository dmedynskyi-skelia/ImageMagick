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

  MagickWand Application Programming Interface declarations.
*/

#ifndef MAGICKWAND_MAGICKWAND_H
#define MAGICKWAND_MAGICKWAND_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#if !defined(MAGICKWAND_CONFIG_H)
# define MAGICKWAND_CONFIG_H
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

#define MAGICKWAND_CHECK_VERSION(major,minor,micro) \
  ((MAGICKWAND_MAJOR_VERSION > (major)) || \
    ((MAGICKWAND_MAJOR_VERSION == (major)) && \
     (MAGICKWAND_MINOR_VERSION > (minor))) || \
    ((MAGICKWAND_MAJOR_VERSION == (major)) && \
     (MAGICKWAND_MINOR_VERSION == (minor)) && \
     (MAGICKWAND_MICRO_VERSION >= (micro))))

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <time.h>

#if defined(WIN32) || defined(WIN64)
#  define MAGICKWAND_WINDOWS_SUPPORT
#else
#  define MAGICKWAND_POSIX_SUPPORT
#endif 

typedef struct _MagickWand
  MagickWand;

#include "ImageMagick7/MagickWand/method-attribute.h"
#include "ImageMagick7/MagickCore/MagickCore.h"
#include "ImageMagick7/MagickWand/animate.h"
#include "ImageMagick7/MagickWand/compare.h"
#include "ImageMagick7/MagickWand/composite.h"
#include "ImageMagick7/MagickWand/conjure.h"
#include "ImageMagick7/MagickWand/convert.h"
#include "ImageMagick7/MagickWand/deprecate.h"
#include "ImageMagick7/MagickWand/display.h"
#include "ImageMagick7/MagickWand/drawing-wand.h"
#include "ImageMagick7/MagickWand/identify.h"
#include "ImageMagick7/MagickWand/import.h"
#include "ImageMagick7/MagickWand/wandcli.h"
#include "ImageMagick7/MagickWand/operation.h"
#include "ImageMagick7/MagickWand/magick-cli.h"
#include "ImageMagick7/MagickWand/magick-property.h"
#include "ImageMagick7/MagickWand/magick-image.h"
#include "ImageMagick7/MagickWand/mogrify.h"
#include "ImageMagick7/MagickWand/montage.h"
#include "ImageMagick7/MagickWand/pixel-iterator.h"
#include "ImageMagick7/MagickWand/pixel-wand.h"
#include "ImageMagick7/MagickWand/stream.h"
#include "ImageMagick7/MagickWand/wand-view.h"

extern WandExport char
  *MagickGetException(const MagickWand *,ExceptionType *);

extern WandExport ExceptionType
  MagickGetExceptionType(const MagickWand *);

extern WandExport MagickBooleanType
  IsMagickWand(const MagickWand *),
  IsMagickWandInstantiated(void),
  MagickClearException(MagickWand *),
  MagickSetIteratorIndex(MagickWand *,const ssize_t);

extern WandExport MagickWand
  *CloneMagickWand(const MagickWand *),
  *DestroyMagickWand(MagickWand *),
  *NewMagickWand(void),
  *NewMagickWandFromImage(const Image *);

extern WandExport ssize_t
  MagickGetIteratorIndex(MagickWand *);

extern WandExport void
  ClearMagickWand(MagickWand *),
  MagickWandGenesis(void),
  MagickWandTerminus(void),
  *MagickRelinquishMemory(void *),
  MagickResetIterator(MagickWand *),
  MagickSetFirstIterator(MagickWand *),
  MagickSetLastIterator(MagickWand *);

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
