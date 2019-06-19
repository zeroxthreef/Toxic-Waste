/* honestly, this could probably be macro-ified, but I havent found a reason to yet */
short read_bitflag(uint64_t value, short bit)
{
	/* shift then use a bitmask */
	value >>= bit;
	value &= 1;
	return value;
}