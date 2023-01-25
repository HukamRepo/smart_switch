cd /Users/gurvindersingh/Documents/Development/learning/connectedhomeip/examples/chip-tool/out/debug
cd /opt/nordic/ncs/v2.1.0


## Template

./scripts/tools/zap/run_zaptool.sh /Users/gurvindersingh/Documents/personal/Technical/hukam/repository/smart_switch/src/light_bulb.zap

## BUILD 
west build -b nrf52840dk_nrf52840 -d build -- -DCONF_FILE=prj.conf

## FLASH build to 683297331
west flash -d /Users/gurvindersingh/Documents/personal/Technical/hukam/repository/smart_switch/build --skip-rebuild --dev-id 683297331

Flashing build to 683297331
west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/light_bulb/build_nrf52840dk_nrf52840 --skip-rebuild -r nrfjprog --dev-id 683297331
west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/light_bulb/build_nrf52840dk_nrf52840
west flash -d /opt/nordic/ncs/v2.1.0/nrf/samples/matter/lock/build_nrf52840dk_nrf52840
west flash -d /Users/gurvindersingh/Documents/Development/learning/thread/repositories/nrf-apps/light_bulb/build --skip-rebuild --dev-id 683297331




NAT64=1 \
DNS64=0 \
DHCPV6_PD=0 \
NETWORK_MANAGER=0 \
BACKBONE_ROUTER=1 \
BORDER_ROUTING=1 \
WEB_GUI=1 \
REST_API=1 \
OTBR_OPTIONS="-DOT_THREAD_VERSION=1.2" \
./script/bootstrap


INFRA_IF_NAME=wlan0 \
BACKBONE_ROUTER=1 \
BORDER_ROUTING=1 \
WEB_GUI=1 \
REST_API=1 \
OTBR_OPTIONS="-DOT_THREAD_VERSION=1.2" \
./script/setup

sudo systemctl status
udo systemctl --failed


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
--volume /dev/ttyACM0:/dev/radio nrfconnect/otbr:1813352 --radio-url spinel+hdlc+uart:////dev/radio?uart-baudrate=1000000 -B wlan0


sudo docker run --rm -it --privileged -d --network host --name otbr -p 8080:80 --volume /dev/ttyACM0:/dev/ttyACM0 nrfconnect/otbr:1813352 --radio-url spinel+hdlc+uart:///dev/ttyACM0 -B wlan0

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


out/debug/chip-tool pairing ble-wifi 1 Gurvinder2.4Ghz 1SatnamW 20202021 3840


sudo docker exec -it otbr sh -c "sudo ot-ctl dataset active -x"


## Actions using Chip-tool (Commissioner)

rm -rf /tmp/chip_*
sudo ot-ctl dataset active -x

dataset set active 0e080000000000010000000300001135060004001fffe00208ae6d22058f18d2e20708fd1371ea5b1611f00510533b2d9c226ddfddac23a347af428cb1030f4f70656e5468726561642d39346431010294d1041066818b48056a61ec9c293a4f79a017050c0402a0f7f8



./chip-tool pairing ble-thread 2 hex:0e080000000000010000000300000f35060004001fffe0020811111111222222220708fd05e82aab2b4c45051000112233445566778899aabbccddeeff030e4f70656e54687265616444656d6f010212340410445f2b5ca6f2a93a55ce570a70efeecb0c0402a0f7f8 20202021 3840

out/debug/chip-tool pairing onnetwork 1 20202021

out/debug/chip-tool pairing onnetwork-long 1 20202021 3840

out/debug/chip-tool basic read vendor-name 25 1


./chip-tool pairing unpair 2

out/debug/chip-tool onoff toggle <node_id> <endpoint_id>
./chip-tool onoff toggle 2 1

./chip-tool levelcontrol move-to-level 5 5 0 0 2 1

./chip-tool onoff on 1 1
./chip-tool temperaturemeasurement read measured-value 1 1
./chip-tool onoff off 1 1




--------------------

## Install OTBR Manually (Raspberry Pi)

Reference: https://openthread.io/codelabs/openthread-border-router#1

```

git clone https://github.com/openthread/ot-br-posix.git --depth 1
cd ot-br-posix
./script/bootstrap
INFRA_IF_NAME=wlan0 ./script/setup

sudo service mdns status
sudo service otbr-agent status
sudo service otbr-agent restart
sudo service otbr-web status
sudo systemctl status tayga

sudo ot-ctl reset
sudo ot-ctl dataset init new
sudo ot-ctl dataset commit active
sudo ot-ctl prefix add fd11:22::/64 paros med
sudo ot-ctl route add 64:ff9b::/96 s med
sudo ot-ctl ifconfig up
sudo ot-ctl thread start
sudo ot-ctl netdata register
sudo ot-ctl state

sudo ot-ctl dataset active -x


ping 64:ff9b::808:808

sudo ot-ctl ping 64:ff9b::808:808


sudo route -A inet6 add 64:ff9b::/96 dev wpan0


ot dataset networkname OpenThreadDemo
ot dataset networkkey 00112233445566778899aabbccddeeff
ot dataset commit active
ot ifconfig down
ot ifconfig up
ot thread start
ot netdata show


```

## TROUUBLESHOOTING

```

rm -rf ~/.ssh/known_hosts

journalctl -xe

sudo systemctl status avahi-daemon.service
sudo systemctl restart avahi-daemon.service


# /etc/init.d/avahi-daemon 
Usage: /etc/init.d/avahi-daemon {start|stop|status|restart|condrestart}


sudo ot-ctl netdata show
sudo ot-ctl ipaddr
cat /var/log/syslog | grep otbr-agent


root@otbr:~/ot-br-posix# sudo ot-ctl netdata show
Prefixes:
fd67:14bb:128f:1::/64 paos low b800
Routes:
fdcf:846a:9c18:f389::/64 s med b800
Services:
44970 01 03000500000e10 s b800
44970 5d fd51c53352638f2b15d0c9729094cc89d120 s b800


systemctl stop otbr-web
systemctl disable otbr-web
rm /etc/systemd/system/otbr-web
rm /etc/systemd/system/otbr-web # and symlinks that might be related
rm /usr/lib/systemd/system/otbr-web 
rm /usr/lib/systemd/system/otbr-web # and symlinks that might be related
systemctl daemon-reload
systemctl reset-failed

systemctl stop otbr-agent
systemctl disable otbr-agent
rm /etc/systemd/system/otbr-agent
rm /usr/lib/systemd/system/otbr-agent 
rm /usr/lib/systemd/system/otbr-agent # and symlinks that might be related
systemctl daemon-reload
systemctl reset-failed

systemctl stop mdns
systemctl disable mdns
rm /etc/systemd/system/mdns
rm /usr/lib/systemd/system/mdns 
rm /usr/lib/systemd/system/mdns # and symlinks that might be related
systemctl daemon-reload
systemctl reset-failed

ifconfig
route -n
route -6 -n

sudo route -A inet6 add 64:ff9b::/96 dev wpan0


```

## AWS IoT Core

### Create / Register Certificates for Device provisioning

```

openssl genrsa -out rootCA.key 2048
openssl req -x509 -new -key rootCA.key -days 3650 -out rootCA.pem

openssl genrsa -out verification_cert_key_aws.key 2048

openssl req -new \
    -key verification_cert_key_aws.key \
    -out verification_cert_csr_aws.csr

openssl x509 -req \
    -in verification_cert_csr_aws.csr \
    -CA rootCA.pem \
    -CAkey rootCA.key \
    -CAcreateserial \
    -out verification_cert_aws.pem \
    -days 500 -sha256


openssl x509 -req \
    -in verification_cert_csr_aws.csr \
    -CA root_CA_cert.pem \
    -CAkey root_CA_key.key \
    -CAcreateserial \
    -extensions v3_ca \
    -out verification_cert_aws.pem \
    -days 500 -sha256
    


openssl verify -verbose -CAfile root_CA_cert.pem verification_cert_aws.pem


openssl genrsa -out rootCA.key 2048
openssl req -x509 -new -key rootCA.key -days 3650 -out rootCA.pem \
-subj '/C=AA/ST=AA/L=AA/O=AA Ltd/OU=AA/CN=AA/emailAddress=aa@aa.com'

openssl genrsa -out client1.key 2048
openssl req -new -key client1.key -out client1.csr \
-subj '/C=BB/ST=BB/L=BB/O=BB Ltd/OU=BB/CN=BB/emailAddress=bb@bb.com'

openssl x509 -req -days 365 -CA rootCA.pem -CAkey rootCA.key \
-CAcreateserial -CAserial serial -in client1.csr -out client1.pem

openssl verify -verbose -CAfile rootCA.pem client1.pem


```


## REFERENCES

    - [OTBR](https://openthread.io/guides/border-router/build)
    - [Good Setup Demo](https://golioth.github.io/golioth-openthread-demo-docs/docs/intro)
    - [nRF Samples](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/nrf/samples/matter/light_bulb/README.html)
    - [nRF West tool](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/zephyr/develop/west/build-flash-debug.html)
    - [nRF Thread Tools](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.0.0/nrf/ug_thread_tools.html)
    - [Thread CHIP Tool](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/matter/chip_tool_guide.html)
    - [nRF Custom Template](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/nrf/ug_matter_gs_adding_clusters.html#ug-matter-creating-accessory)
    - [Matter Compliant](https://www.digicert.com/blog/how-to-become-matter-compliant)



