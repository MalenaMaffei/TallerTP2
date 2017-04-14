echo "-----------------prueba 1------------------"
./tp tests/t1/always.cfg tests/t1/one.cap
echo
echo "-----------------prueba 2------------------"
./tp tests/t2/all_of.cfg tests/t2/multiple_packets.cap
echo
echo "-----------------prueba 3------------------"
./tp tests/t3/any_of.cfg tests/t3/multiple_packets.cap
echo
echo "-----------------prueba 4------------------"
./tp tests/t4/3to4.cfg tests/t4/multiple_packets.cap
echo
echo "-----------------prueba 5------------------"
./tp tests/t5/elite_4_or_more.cfg tests/t5/elite.cap
echo "-----------------prueba 6------------------"
./tp tests/t6/spoon.cfg tests/t6/packet_fragmented.cap
echo
echo "-----------------prueba 7------------------"
./tp tests/t7/spoon.cfg tests/t7/packet_fragmented.cap
echo
echo "-----------------prueba 8------------------"
./tp tests/t8/rules.cfg tests/t8/packets.cap
echo
echo "-----------------prueba 9------------------"
./tp tests/t9spoon.cfg tests/t9/cap0.cap tests/t9/cap1.cap tests/t9/cap2.cap tests/t9/cap3.cap tests/t9/cap4.cap
