include recipes-core/images/core-image-minimal.bb

IMAGE_INSTALL += " \
    storm-player \
    kernel-modules \
"

EXTRA_IMAGE_FEATURES += "read-only-rootfs"
