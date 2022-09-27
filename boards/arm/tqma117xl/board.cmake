if(CONFIG_SOC_MIMXRT1176_CM7)
board_runner_args(pyocd "--target=mimxrt1170_cm7")
board_runner_args(jlink "--device=MIMXRT1170_FLEXSPI1_UFL" "--reset-after-load")
endif()

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
