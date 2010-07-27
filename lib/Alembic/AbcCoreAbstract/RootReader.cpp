//-*****************************************************************************
//
// Copyright (c) 2009-2010,
//  Sony Pictures Imageworks Inc. and
//  Industrial Light & Magic, a division of Lucasfilm Entertainment Company Ltd.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// *       Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// *       Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// *       Neither the name of Sony Pictures Imageworks, nor
// Industrial Light & Magic, nor the names of their contributors may be used
// to endorse or promote products derived from this software without specific
// prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//-*****************************************************************************

#include <Alembic/AbcCoreAbstract/RootReader.h>

namespace Alembic {
namespace AbcCoreAbstract {
namespace v1 {

//-*****************************************************************************
const std::string &RootReader::getName() const
{
    static std::string rootName( "" );
    return rootName;
}

//-*****************************************************************************
const std::string &RootReader::getFullName() const
{
    static std::string rootName( "" );
    return rootName;
}

//-*****************************************************************************
// Must use dynamic cast for subtle reasons.
RootReaderPtr RootReader::getRoot()
{
    RootReaderPtr sptr =
        boost::dynamic_pointer_cast<RootReader, ObjectReader>( asObject() );
    ABCA_ASSERT( sptr.get() == this,
                 "Corrupt shared pointer dynamic cast" );
    return sptr;
}

//-*****************************************************************************
ObjectReaderPtr RootReader::getParent()
{
    return ObjectReaderPtr();
}

} // End namespace v1
} // End namespace AbcCoreAbstract
} // End namespace Alembic


