zephyr_library()

zephyr_library_sources_ifdef(CONFIG_BOOT_FLEXSPI_NOR src/xip/tq_flexspi_nor_config.c)
zephyr_include_directories_ifdef(CONFIG_BOOT_FLEXSPI_NOR src/xip/)

zephyr_library_sources_ifdef(CONFIG_DEVICE_CONFIGURATION_DATA src/dcd.c)

zephyr_library_sources(src/clock_config.c)
zephyr_include_directories(src)

# zephyr_library_compile_definitions(SKIP_POWER_ADJUSTMENT)
zephyr_library_compile_definitions(SKIP_DCDC_ADJUSTMENT)
