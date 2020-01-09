DEPENDS = "gstreamer1.0-libav gstreamer1.0-plugins-good"

LICENSE_FLAGS = "commercial"

inherit systemd

SRC_URI += "file://storm.service"

SYSTEMD_SERVICE_${PN} = "storm.service"

do_install_append() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/storm.service ${D}${systemd_unitdir}/system
    sed -i -e 's,@BINDIR@,${bindir},g' ${D}${systemd_unitdir}/system/storm.service
}