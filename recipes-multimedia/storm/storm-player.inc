DEPENDS = "gstreamer1.0-libav gstreamer1.0-plugins-good"

LICENSE_FLAGS = "commercial"

inherit systemd

SRC_URI += " \
    file://storm.service \
    file://storm \
"

SYSTEMD_SERVICE_${PN} = "storm.service"

do_install_append() {
    install -d ${D}${systemd_unitdir}/system
    install -m 0644 ${WORKDIR}/storm.service ${D}${systemd_unitdir}/system
    sed -i -e 's,@BINDIR@,${bindir},g' ${D}${systemd_unitdir}/system/storm.service

    install -d ${D}${sysconfdir}/default
	install -m 0644 ${WORKDIR}/storm ${D}${sysconfdir}/default
    sed -i -e 's,@SYSCONFDIR@,${sysconfdir},g' ${D}${systemd_unitdir}/system/storm.service
}