/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2015 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


//
// A text reader for a stream.
//


#ifndef BSTONE_TEXT_READER_INCLUDED
#define BSTONE_TEXT_READER_INCLUDED


#include <array>
#include <string>
#include "bstone_istream.h"


namespace bstone
{


class TextReader final
{
public:
    TextReader();

    TextReader(
        IStream* stream);

    TextReader(
        const TextReader& that) = delete;

    TextReader& operator=(
        const TextReader& that) = delete;

    ~TextReader();


    bool open(
        IStream* stream);

    void close();

    bool is_open() const;


    bool is_eos() const;


    std::string read_line();


private:
    static constexpr int max_buffer_size = 4096;


    using Buffer = std::array<char, max_buffer_size>;


    IStream* stream_;
    bool is_eos_;
    int buffer_offset_;
    int buffer_size_;
    Buffer buffer_;
    int char_buffer_;

    int peek_char();
}; // TextReader


} // bstone


#endif // BSTONE_TEXT_READER_INCLUDED
