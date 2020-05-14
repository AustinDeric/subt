/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */


#include <ignition/common/Console.hh>

#include "ConnectionHelper.hh"

std::map<std::string, std::vector<ignition::math::Vector3d>>
  subt::ConnectionHelper::connectionPoints =
  {
    {"Urban Straight", {{0, 20, 0}, {0, -20, 0}}},
    {"Urban Straight Lights", {{0, 20, 0}, {0, -20, 0}}},
    {"Urban Bend Right", {{0, -20, 0}, {20, 0, 0}}},
    {"Urban Bend Left", {{0, -20, 0}, {-20, 0, 0}}},
    {"Urban Bend Left Lights", {{0, -20, 0}, {-20, 0, 0}}},
    {"Urban Superpose", {{0, 20, 0}, {0, -20, 0}, {-20, 0, 10}, {20, 0, 10}}},
    {"Urban 3-Way Right Intersection", {{0, 20, 0}, {0, -20, 0}, {20, 0, 0}}},
    {"Urban Straight Door Right",
        {{20, 0, 0}, {-20, 0, 0}, {-16.021, 3.94, 0.94}}},
    {"Urban Straight Door Left",
        {{20, 0, 0}, {-20, 0, 0}, {-16.021, -3.94, 0.94}}},
    {"Urban Straight Door Right Flipped",
        {{20, 0, 0}, {-20, 0, 0}, {-16.021, 3.94, 0.94}}},
    {"Urban Straight Door Right Flipped Lights",
        {{20, 0, 0}, {-20, 0, 0}, {-16.021, 3.94, 0.94}}},
    {"Urban Straight Door Left Flipped",
        {{20, 0, 0}, {-20, 0, 0}, {-16.021, -3.94, 0.94}}},
    {"Urban Straight Door Right Extension",
        {{20, 0, 0}, {-20, 0, 0}, {0, 20, 0}}},
    {"Urban Straight Door Right Extension Lights",
        {{20, 0, 0}, {-20, 0, 0}, {0, 20, 0}}},
    {"Urban Service Room Centered", {{0, 20, 0}}},
    {"Urban Service Room Centered Lights", {{0, 20, 0}}},
    {"Urban Service Room", {{-16.023, 3.906, 0.919}}},
    {"Urban Service Room Lights", {{-16.023, 3.906, 0.919}}},
    {"Urban Service Room Straight", {{0, -20, 0}, {0, 20, 0}}},
    {"Urban Service Room Straight Lights", {{0, -20, 0}, {0, 20, 0}}},
    {"Urban Platform", {{20, 0, 0}, {-20, 0, 0}, {0, 20, 1.7},
        {23.979, 3.906, 0.94}, {-23.979, 3.906, 0.94}}},
    {"Urban Platform Open", {{20, 0, 0}, {-20, 0, 0}, {0, 20, 0},
        {23.979, 3.906, 0.919}, {-23.979, 3.906, 0.919},
        {23.982, 11.743, 0.919}}},
    {"Urban Stairwell Platform", {{0, 20, 11.69}, {0, -20, 1.69}}},
    {"Urban Stairwell Platform Lights", {{0, 20, 11.69}, {0, -20, 1.69}}},
    {"Urban Stairwell Platform Centered", {{0, 20, 10}, {0, -20, 0}}},
    {"Urban Stairwell Platform Centered Lights", {{0, 20, 10}, {0, -20, 0}}},
    {"Urban Starting Area", {{-16.021, 3.94, 0.919}}},
    {"Urban Elevation Up", {{0, 20, 5}, {0, -20, 0}}},
    {"Urban Elevation Up Lights", {{0, 20, 5}, {0, -20, 0}}},
    {"Urban Elevation Down", {{0, 20, 0}, {0, -20, 5}}},
    {"Urban 2 Story", {{0, 20, 10}, {0, -20, 0}, {-20, 0, 10}, {20, 0, 0}}},
    {"Urban 2 Story Lights",
        {{0, 20, 10}, {0, -20, 0}, {-20, 0, 10}, {20, 0, 0}}},
    {"Urban 2 Story Large Side 1 Lights", {{0, 20, 10}, {0, -20, 0}}},
    {"Urban 2 Story Large Side 2 Lights", {{0, -20, 0}, {0, 20, 0}}},
    {"Urban Large Room Split", {{0, -20, 0}, {-20, 0, 0}, {0, 20, 0}}},
    {"Urban Large Room Split Lights", {{0, -20, 0}, {-20, 0, 0}, {0, 20, 0}}},
    {"Cave Starting Area", {{12.5, 0, 0}}},
    {"Cave Straight 01", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 01 Lights", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 02", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 02 Lights", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 03", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 04", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 04 Lights", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 05", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Straight 05 Lights", {{0, 12.5, 0}, {0, -12.5, 0}}},
    {"Cave Corner 01", {{-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 01 Lights", {{-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 02", {{-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 02 Lights", {{-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave 3 Way 01", {{12.5, 0, 0}, {-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave 3 Way 01 Lights", {{12.5, 0, 0}, {-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Elevation", {{0, 12.5, 0}, {0, -12.5, 10}}},
    {"Cave Elevation Lights", {{0, 12.5, 0}, {0, -12.5, 10}}},
    {"Cave Vertical Shaft", {{0, 12.5, 20}, {0, -12.5, 0}}},
    {"Cave Vertical Shaft Lights", {{0, 12.5, 20}, {0, -12.5, 0}}},
    {"Cave Cavern Split 01", {{0, 25, 25}, {12.5, 0, 0}, {-12.5, 0, 0}}},
    {"Cave Cavern Split 02", {{12.5, 0, 0}, {-12.5, 0, 0}}},
    {"Cave Corner 30", {{12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 30F", {{-12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 30 D", {{12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 30 D Lights", {{12.5, 0, 0}, {0, 12.5, 0}}},
    {"Cave Corner 30F D", {{12.5, 0, 0}, {0, -12.5, 0}}},
    {"Cave Corner 30F D Lights", {{12.5, 0, 0}, {0, -12.5, 0}}}
  };

std::map<std::string, subt::ConnectionHelper::ConnectionType>
  subt::ConnectionHelper::connectionTypes =
  {
    {"Urban Straight", subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Bend Right", subt::ConnectionHelper::TURN},
    {"Urban Bend Left", subt::ConnectionHelper::TURN},
    {"Urban Bend Left Lights", subt::ConnectionHelper::TURN},
    {"Urban Superpose", subt::ConnectionHelper::TURN},
    {"Urban 3-Way Right Intersection", subt::ConnectionHelper::TURN},
    {"Urban Straight Door Right", subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Door Left", subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Door Right Flipped", subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Door Right Flipped Lights",
        subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Door Left Flipped", subt::ConnectionHelper::STRAIGHT},
    {"Urban Straight Door Right Extension", subt::ConnectionHelper::TURN},
    {"Urban Straight Door Right Extension Lights",
        subt::ConnectionHelper::TURN},
    {"Urban Service Room Centered", subt::ConnectionHelper::STRAIGHT},
    {"Urban Service Room Centered Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Service Room", subt::ConnectionHelper::STRAIGHT},
    {"Urban Service Room Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Service Room Straight", subt::ConnectionHelper::STRAIGHT},
    {"Urban Service Room Straight Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Platform", subt::ConnectionHelper::TURN},
    {"Urban Platform Open", subt::ConnectionHelper::TURN},
    {"Urban Stairwell Platform", subt::ConnectionHelper::STRAIGHT},
    {"Urban Stairwell Platform Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Stairwell Platform Centered", subt::ConnectionHelper::STRAIGHT},
    {"Urban Stairwell Platform Centered Lights",
      subt::ConnectionHelper::STRAIGHT},
    {"Urban Starting Area", subt::ConnectionHelper::STRAIGHT},
    {"Urban Elevation Up", subt::ConnectionHelper::STRAIGHT},
    {"Urban Elevation Up Lights", subt::ConnectionHelper::STRAIGHT},
    {"Urban Elevation Down", subt::ConnectionHelper::STRAIGHT},
    {"Urban 2 Story", subt::ConnectionHelper::TURN},
    {"Urban 2 Story Lights", subt::ConnectionHelper::TURN},
    {"Urban 2 Story Large Side 1 Lights", subt::ConnectionHelper::TURN},
    {"Urban 2 Story Large Side 2 Lights", subt::ConnectionHelper::TURN},
    {"Urban Large Room Split", subt::ConnectionHelper::TURN},
    {"Urban Large Room Split Lights", subt::ConnectionHelper::TURN},
    {"Cave Starting Area", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 01", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 01 Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 02", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 02 Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 03", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 04", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 04 Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 05", subt::ConnectionHelper::STRAIGHT},
    {"Cave Straight 05 Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Corner 01", subt::ConnectionHelper::TURN},
    {"Cave Corner 01 Lights", subt::ConnectionHelper::TURN},
    {"Cave Corner 02", subt::ConnectionHelper::TURN},
    {"Cave Corner 02 Lights", subt::ConnectionHelper::TURN},
    {"Cave 3 Way 01", subt::ConnectionHelper::TURN},
    {"Cave 3 Way 01 Lights", subt::ConnectionHelper::TURN},
    {"Cave Elevation", subt::ConnectionHelper::STRAIGHT},
    {"Cave Elevation Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Vertical Shaft", subt::ConnectionHelper::STRAIGHT},
    {"Cave Vertical Shaft Lights", subt::ConnectionHelper::STRAIGHT},
    {"Cave Cavern Split 01", subt::ConnectionHelper::TURN},
    {"Cave Cavern Split 02", subt::ConnectionHelper::STRAIGHT},
    {"Cave Corner 30", subt::ConnectionHelper::TURN},
    {"Cave Corner 30F", subt::ConnectionHelper::TURN},
    {"Cave Corner 30 D", subt::ConnectionHelper::TURN},
    {"Cave Corner 30 D Lights", subt::ConnectionHelper::TURN},
    {"Cave Corner 30F D", subt::ConnectionHelper::TURN},
    {"Cave Corner 30F D Lights", subt::ConnectionHelper::TURN}
  };

using namespace ignition;
using namespace subt;

/////////////////////////////////////////////////
bool ConnectionHelper::ComputePoint(VertexData *_tile1, VertexData *_tile2,
    ignition::math::Vector3d& _pt)
{
  if (!ConnectionHelper::connectionPoints.count(_tile1->tileType))
  {
    ignwarn << "No connection information for: " << _tile1->tileType
            << std::endl;
    return false;
  }

  if (!ConnectionHelper::connectionPoints.count(_tile2->tileType))
  {
    ignwarn << "No connection information for: " << _tile2->tileType
            << std::endl;
    return false;
  }

  for (const auto& pt1 : ConnectionHelper::connectionPoints[_tile1->tileType])
  {
    auto pt1tf = _tile1->model.Pose().CoordPositionAdd(pt1);
    for (const auto& pt2 : ConnectionHelper::connectionPoints[_tile2->tileType])
    {
      auto pt2tf = _tile2->model.Pose().CoordPositionAdd(pt2);
      if (pt1tf.Equal(pt2tf, 1))
      {
        _pt = pt1tf;
        return true;
      }
    }
  }

  ignwarn << "Failed to connect: " << _tile1->tileType << " "
          << _tile2->tileType << std::endl;

  for (const auto& pt1 : ConnectionHelper::connectionPoints[_tile1->tileType])
  {
    auto pt1tf = _tile1->model.Pose().CoordPositionAdd(pt1);
    for (const auto& pt2 :
        ConnectionHelper::connectionPoints[_tile2->tileType])
    {
      auto pt2tf = _tile2->model.Pose().CoordPositionAdd(pt2);
      igndbg <<
        _tile1->tileType << " [" << _tile1->model.Pose() << "] -- " <<
        _tile2->tileType << " [" << _tile2->model.Pose() << "]"
                         << " [" <<  pt1tf << "] [" << pt2tf << "]"
                         << std::endl;
    }
  }

  return false;
}
