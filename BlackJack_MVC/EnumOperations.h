#pragma once

template <class _EnumName, _EnumName _First, _EnumName _Last>
class NextEnum
{
public:
	_EnumName operator ()(_EnumName value)
	{
		switch (value)
		{
			case _Last:
				return _First;
			default:
				return static_cast<_EnumName>(value + 1);
		}
	}
};

template <class _EnumName, _EnumName _First, _EnumName _Last>
class PrevEnum
{
public:
	_EnumName operator ()(_EnumName value)
	{
		switch (value)
		{
			case _First:
				return _Last;
			default:
				return static_cast<_EnumName>(value - 1);
		}
	}
};

