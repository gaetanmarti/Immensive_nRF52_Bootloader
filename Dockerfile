FROM hardwario/gcc-arm-embedded-nrf52:latest
ENTRYPOINT []
WORKDIR /opt/project/armgcc
VOLUME ["/opt/project/armgcc"]
CMD ["bash"]