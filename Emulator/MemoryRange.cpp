#include "MemoryRange.hpp"

MemoryRange::MemoryRange() :
	MemoryRange("Uninitialized", 0, 0)
{ }

MemoryRange::MemoryRange(const char* name, uint16_t begin, uint16_t end) :
	_name(name),
	_begin(begin),
	_end(end)
{
	_data.resize(end - begin + 1, 0);
}

uint8_t MemoryRange::read8(uint16_t addr)
{
	return _data[addr - _begin];
}

void MemoryRange::write8(uint16_t addr, uint8_t v)
{
	_data[addr - _begin] = v;
}

bool MemoryRange::isInRange(uint16_t addr) const
{
	return _begin <= addr && addr <= _end;
}

size_t MemoryRange::size() const
{
	return _data.size();
}

const char* MemoryRange::name() const
{
	return _name;
}