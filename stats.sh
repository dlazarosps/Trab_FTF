#!/bin/bash
# echo "SDCs: "
# grep -r -i SDC summary-carolfi.log |wc -l
# echo "SDCs Detected: "
# grep -r -i "SDC Detected" summary-carolfi.log |wc -l
# echo "Hangs: "
# grep -r -i HANG summary-carolfi.log |wc -l
# echo "Masked: "
# grep -r -i Masked summary-carolfi.log |wc -l
# echo "Failed: "
# grep -r -i Failed summary-carolfi.log |wc -l

TOTAL=$(grep -r -i -e 'Failed\|Masked\|HANG\|SDC\|"SDC Detected"' summary-carolfi.log |wc -l)

while [ $TOTAL -lt 10001 ]; do
	clear
	
	echo "SDCs: "
	grep -r -i SDC summary-carolfi.log |wc -l
	echo "SDCs Detected: "
	grep -r -i "SDC Detected" summary-carolfi.log |wc -l
	echo "Hangs: "
	grep -r -i HANG summary-carolfi.log |wc -l
	echo "Masked: "
	grep -r -i Masked summary-carolfi.log |wc -l
	echo "Failed: "
	grep -r -i Failed summary-carolfi.log |wc -l
	echo "Total: "
	grep -r -i -e 'Failed\|Masked\|HANG\|SDC\|"SDC Detected"' summary-carolfi.log |wc -l

	TOTAL=$(grep -r -i -e 'Failed\|Masked\|HANG\|SDC\|"SDC Detected"' summary-carolfi.log |wc -l)
	
	sleep 0.2
done

killall -9 watchdog.py
killall -9 fault_injector.py
killall -9 gdb