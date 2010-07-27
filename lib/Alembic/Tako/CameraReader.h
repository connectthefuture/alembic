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

#ifndef _Alembic_Tako_CameraReader_h_
#define _Alembic_Tako_CameraReader_h_

#include <Alembic/Tako/Foundation.h>
#include <Alembic/Tako/HDFReaderNode.h>
#include <Alembic/Tako/CameraDef.h>

namespace Alembic {

namespace Tako {

namespace TAKO_LIB_VERSION_NS {

class TransformReader;

/**
\brief CameraReader is used to read camera data from the HDF file.
*/
class CameraReader : public HDFReaderNode
{
    public:

        /**
        \brief The hint of what camera data was read.

        This enumeration helps to provide a hint about whether the camera is
        static, or animated.
        */
        enum
        {
            /** Indicates that the camera does not have per frame data. */
            CAMERA_STATIC = 0,

            /** Indicates that the camera has per frame data. */
            CAMERA_ANIMATED,

            /** Indicates that there was a problem reading the camera data.
            This will occur when an illegal frame for an animated camera is
            attempted to be read.
            */
            READ_ERROR
        };

        /**
        \brief Constructor requires a node name and a parent node.
        \param iName The name of the node to read.
        \param iParent The parent transform node.
        */
        CameraReader(const char * iName, TransformReader & iParent);

        /**
        \brief Destructor
        */
        ~CameraReader();


        /**
        \brief Gets the list of frame samples.
        \param ioFrames The set of frame samples to be added to.

        This function adds any frames samples it finds for this node to
        ioFrames.  Since ioFrames is a set, duplicates are automatically
        elminiated.
        */
        void getFrames(std::set<float>& ioFrames) const;

        /**
        \brief Returns whether or not this node has any frame samples.
        \return true if this node has at least one frame sample, false if it
        is static.

        This is a convenience functions which returns whether or not the node
        has any frame samples.
        */
        bool hasFrames() const;

        /**
        \brief Attempts to read the camera at the given frame.
        \param iFrame The frame at which to read the camera.
        \return Whether the static or animated data was read, or whether
        there was an error reading the data.
        */
        unsigned int read(float iFrame);

        /**
        All of the information about the camera for the frame at which it was
        read.
        */
        CameraData mCameraData;

    private:
        // disallow copying
        CameraReader(const CameraReader &);
        void operator=(const CameraReader &);

        class PrivateData;
        boost::scoped_ptr < PrivateData > mData;
};
}

using namespace TAKO_LIB_VERSION_NS;  // NOLINT
}

} // End namespace Alembic

#endif  // _Alembic_Tako_CameraReader_h_

