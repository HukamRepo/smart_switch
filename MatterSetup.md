
NAT64=1 \
DNS64=0 \
DHCPV6_PD=0 \
NETWORK_MANAGER=0 \
BACKBONE_ROUTER=1 \
BORDER_ROUTING=1 \
WEB_GUI=1 \
REST_API=1 \
./script/bootstrap

INFRA_IF_NAME=wlan0 WEB_GUI=1 ./script/setup


sudo modprobe ip6table_filter
docker run -it --rm --privileged --name otbr \
--sysctl "net.ipv6.conf.all.disable_ipv6=0 net.ipv4.conf.all.forwarding=1 net.ipv6.conf.all.forwarding=1" \
-p 8080:80 --dns=127.0.0.1 --volume /dev/ttyACM0:/dev/ttyACM0 openthread/otbr --radio-url spinel+hdlc+uart:///dev/ttyACM0?uart-baudrate=1000000 -B wlan0




sudo modprobe ip6table_filter
docker run -it --rm --privileged --name otbr \
--sysctl "net.ipv6.conf.all.disable_ipv6=0 net.ipv4.conf.all.forwarding=1 net.ipv6.conf.all.forwarding=1" \
-p 8080:80 --dns=127.0.0.1 --volume /dev/ttyACM0:/dev/ttyACM0 openthread/otbr --radio-url spinel+hdlc+uart:///dev/ttyACM0?uart-baudrate=1000000 -B wlan0


sudo sysctl net.ipv6.conf.wlan0.accept_ra=2
sudo sysctl net.ipv6.conf.wlan0.accept_ra_rt_info_max_plen=128

sudo docker network create --ipv6 --subnet fd11:db8:1::/64 -o com.docker.network.bridge.name=otbr0 otbr


sudo modprobe ip6table_filter

sudo docker run -it --rm --privileged --name otbr --network otbr -p 8080:80 \
--sysctl "net.ipv6.conf.all.disable_ipv6=0 net.ipv4.conf.all.forwarding=1 net.ipv6.conf.all.forwarding=1" \
--volume /dev/ttyACM0:/dev/radio nrfconnect/otbr:1813352 --radio-url spinel+hdlc+uart:///dev/radio?uart-baudrate=1000000

sudo modprobe ip6table_filter
sudo docker run -it --rm --privileged --name otbr --network otbr -p 8080:80 \
--sysctl "net.ipv6.conf.all.disable_ipv6=0 net.ipv4.conf.all.forwarding=1 net.ipv6.conf.all.forwarding=1" \
--volume /dev/ttyACM0:/dev/radio nrfconnect/otbr:4b04548 --radio-url spinel+hdlc+uart:///dev/radio?uart-baudrate=1000000


sudo modprobe ip6table_filter
sudo docker run -it --rm --privileged --name otbr --network host -p 8080:80 \
--volume /dev/ttyACM0:/dev/radio nrfconnect/otbr:4b04548 --radio-url spinel+hdlc+uart:////dev/radio?uart-baudrate=1000000 -B wlan0


sudo docker run --rm -it --privileged -d --network host --name otbr -p 8080:80 --volume /dev/ttyACM0:/dev/ttyACM0 nrfconnect/otbr:4b04548 --radio-url spinel+hdlc+uart:///dev/ttyACM0 -B wlan0

fd11:22::

sudo ip -6 route add fd11:22:: dev otbr0 via fd11:db8:1::2

sudo docker exec -it otbr sh -c "sudo service otbr-agent status"

sudo docker exec -it otbr sh -c "sudo ot-ctl state"

sudo docker exec -it otbr sh -c "sudo ot-ctl dataset active -x"

sudo docker exec -it otbr sh -c "sudo ot-ctl dataset init new"
sudo docker exec -it otbr sh -c "sudo ot-ctl dataset commit active"
sudo docker exec -it otbr sh -c "sudo ot-ctl ifconfig up"
sudo docker exec -it otbr sh -c "sudo ot-ctl thread start"

sudo docker exec -it otbr sh -c "sudo service mdns status"
sudo docker exec -it otbr sh -c "sudo service otbr-agent status"
sudo docker exec -it otbr sh -c "sudo service otbr-web status"



sudo docker run --rm -it --privileged -d --network host --name otbr --volume /dev/ttyACM0:/dev/ttyACM0 nrfconnect/otbr:1813352 --radio-url spinel+hdlc+uart:///dev/ttyACM0 -B wlan0


out/debug/chip-tool pairing ble-wifi 0X11 Gurvinder2.4Ghz 1SatnamW 20202021 3840

out/debug/chip-tool -ble 3840 20202021 1

out/debug/chip-tool pairing unpair 1

out/debug/chip-tool pairing onnetwork-long 1 20202021 3840


west build -b nrf52840dk_nrf52840 -d build1 -- -DCONF_FILE=prj.conf

Flashing build to 683297331
west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/light_bulb/build_nrf52840dk_nrf52840 --skip-rebuild -r nrfjprog --dev-id 683297331

west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/light_bulb/build_nrf52840dk_nrf52840

west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/lock/build_nrf52840dk_nrf52840



out/debug/chip-tool pairing ble-wifi 1 Gurvinder2.4Ghz 1SatnamW 20202021 3840


sudo docker exec -it otbr sh -c "sudo ot-ctl dataset active -x"


## Actions using Chip-tool (Commissioner)

rm -rf /tmp/chip_*


out/debug/chip-tool pairing ble-thread 1 hex:0e080000000000010000000300000f35060004001fffe0020811111111222222220708fd7ec6c9461d2eb1051000112233445566778899aabbccddeeff030e4f70656e54687265616444656d6f010212340410445f2b5ca6f2a93a55ce570a70efeecb0c0402a0f7f8 20202021 3840

out/debug/chip-tool pairing onnetwork 1 20202021

out/debug/chip-tool pairing onnetwork-long 1 20202021 3840

out/debug/chip-tool basic read vendor-name 25 1


out/debug/chip-tool pairing unpair 25

out/debug/chip-tool onoff toggle <node_id> <endpoint_id>
out/debug/chip-tool onoff toggle 1 1

out/debug/chip-tool levelcontrol move-to-level 100 5 0 0 1 1



--------------------

## Install OTBR Manually (Raspberry Pi)

Reference: https://openthread.io/codelabs/openthread-border-router#1

```

git clone https://github.com/openthread/ot-br-posix.git --depth 1
cd ot-br-posix
./script/bootstrap
INFRA_IF_NAME=wlan0 ./script/setup

sudo service otbr-agent status
sudo service otbr-agent restart

sudo ot-ctl dataset init new
sudo ot-ctl dataset commit active
sudo ot-ctl ifconfig up
sudo ot-ctl thread start
sudo ot-ctl reset
sudo ot-ctl state

```

## REFERENCES

    - [OTBR](https://openthread.io/guides/border-router/build)
    - [nRF Samples](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/nrf/samples/matter/light_bulb/README.html)
    - [nRF West tool](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/zephyr/develop/west/build-flash-debug.html)
    - [nRF Thread Tools](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.0.0/nrf/ug_thread_tools.html)
    - [Thread CHIP Tool](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/matter/chip_tool_guide.html)
    - [nRF Custom Template](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/nrf/ug_matter_gs_adding_clusters.html#ug-matter-creating-accessory)



