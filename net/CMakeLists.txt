aux_source_directory(. DIR_NET_SRCS)
aux_source_directory(./socket DIR_SOCKET_SRCS)
add_library(net ${DIR_NET_SRCS} ${DIR_SOCKET_SRCS})
