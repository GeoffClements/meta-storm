include recipes-core/images/core-image-minimal.bb

IMAGE_INSTALL += " \
    alsa-utils \
    kernel-modules \
    storm-player \
"

EXTRA_IMAGE_FEATURES += "read-only-rootfs"
