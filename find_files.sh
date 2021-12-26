#!/bin/bash
find . -name '*.c' > cscope.files
find . -name '*.h' >> cscope.files
find ../../../usr/include/std*  -name '*.h' >> cscope.files
find ../../../usr/include/str*  -name '*.h' >> cscope.files
find ../../../usr/include/int*  -name '*.h' >> cscope.files
