# Digi's i.MX platforms common settings
include conf/machine/include/digi-defaults.inc
include conf/machine/include/soc-family.inc

# Disable perf features as 2.6.35.3 fail to build otherwise
PERF_FEATURES_ENABLE = ""

XSERVER_DRIVER = "xf86-video-fbdev"
XSERVER_DRIVER_mx5 = "xf86-video-imxfb"
XSERVER_DRIVER_mx6 = "xf86-video-imxfb-vivante"
XSERVER = "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

# FIXME: Use older versions until Vivante GPU is made compatible
PREFERRED_VERSION_xserver-xorg_mx6 = "2:1.14.4"
PREFERRED_VERSION_directfb_mx6 = "1.6.3"
PREFERRED_VERSION_directfb-examples_mx6 = "1.6.0"

# Ship kernel modules
MACHINE_EXTRA_RRECOMMENDS = "kernel-modules"

# Float-Point setting
DEFAULTTUNE_mx6 ?= "cortexa9hf-neon"

# Sub-architecture support
MACHINE_SOCARCH ?= ""
MACHINE_SOCARCH_mx5 = "${TUNE_PKGARCH}-mx5"
MACHINE_SOCARCH_mx6 = "${TUNE_PKGARCH}-mx6"
PACKAGE_EXTRA_ARCHS_append = " ${MACHINE_SOCARCH}"

MACHINE_ARCH_FILTER = "virtual/kernel"
MACHINE_SOCARCH_FILTER = "libfslcodec libfslvpuwrap libfslparser gst-fsl-plugins"
MACHINE_SOCARCH_FILTER_append_mx5 = " virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl"
MACHINE_SOCARCH_FILTER_append_mx6 = " virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl"

INHERIT += "fsl-dynamic-packagearch"

# Extra udev rules
MACHINE_EXTRA_RRECOMMENDS += "udev-extraconf"

# GStreamer 0.10 plugins
MACHINE_GSTREAMER_PLUGIN ?= "gst-fsl-plugin"

# GStreamer 1.0 plugins
MACHINE_GSTREAMER_1_0_PLUGIN ?= ""
MACHINE_GSTREAMER_1_0_PLUGIN_mx6 ?= "gstreamer1.0-plugins-imx-meta"

# mx5 GPU libraries
GPU_FLAVOUR = "${@base_contains('DISTRO_FEATURES', 'x11', 'x11-', '', d)}"
PREFERRED_PROVIDER_virtual/egl_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"
PREFERRED_PROVIDER_virtual/libgles1_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"
PREFERRED_PROVIDER_virtual/libgles2_mx5 ?= "amd-gpu-${GPU_FLAVOUR}bin-mx51"

# mx6 GPU libraries
PREFERRED_PROVIDER_virtual/egl_mx6 ?= "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgl_mx6 ?= "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgles1_mx6 ?= "gpu-viv-bin-mx6q"
PREFERRED_PROVIDER_virtual/libgles2_mx6 ?= "gpu-viv-bin-mx6q"

EXTRA_IMAGEDEPENDS = "u-boot"

KERNEL_IMAGETYPE = "uImage"

MACHINE_FEATURES = "apm usbgadget usbhost vfat alsa touchscreen"
