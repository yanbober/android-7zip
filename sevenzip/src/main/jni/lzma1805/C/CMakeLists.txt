# yan add for 7zip on android.
# transplant lzma/makefile.gcc to CMakeLists.txt

add_definitions(-Wall -D_7ZIP_ST)
#aux_source_directory(. DIR_LZMA_SOURCE)
add_library(lzma1805 #${DIR_LZMA_SOURCE}
        ./Alloc.c
        ./LzFind.c
        ./LzmaDec.c
        ./LzmaEnc.c
        ./7zFile.c
        ./7zStream.c)
