for i in {0..500};
do 

./tp tests/t1/always.cfg tests/t1/one.cap | diff tests/t1/__stdout__ -

./tp tests/t2/all_of.cfg tests/t2/multiple_packets.cap | diff tests/t2/__stdout__ -


./tp tests/t3/any_of.cfg tests/t3/multiple_packets.cap | diff tests/t3/__stdout__ -

./tp tests/t4/3to4.cfg tests/t4/multiple_packets.cap | diff tests/t4/__stdout__ -

./tp tests/t5/elite_4_or_more.cfg tests/t5/elite.cap | diff tests/t5/__stdout__ -

./tp tests/t6/spoon.cfg tests/t6/packet_fragmented.cap | diff tests/t6/__stdout__ -

./tp tests/t7/spoon.cfg tests/t7/packet_fragmented.cap | diff tests/t7/__stdout__ -

./tp tests/t8/rules.cfg tests/t8/packets.cap | diff tests/t8/__stdout__ -


./tp tests/t9/spoon.cfg tests/t9/cap0.cap tests/t9/cap1.cap tests/t9/cap2.cap tests/t9/cap3.cap tests/t9/cap4.cap | diff tests/t9/__stdout__ -;
done
