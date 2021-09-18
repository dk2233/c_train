find_unix . -name '*.c'  > cscope.files
rem ! -path '*/TC375_BoschCG90x_Dual_SMI8_Vector/*' ! -path '*/TC37x/*'
find_unix . -name '*.h' >>  cscope.files 
rem ! -path '*/TC375_BoschCG90x_Dual_SMI8_Vector/*' !  -path '*/TC37x/*'>> cscope.files

