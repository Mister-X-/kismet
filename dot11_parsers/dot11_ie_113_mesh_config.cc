/*
    This file is part of Kismet

    Kismet is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Kismet is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kismet; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "dot11_ie_113_mesh_config.h"

void dot11_ie_113_mesh_config::parse(std::shared_ptr<kaitai::kstream> p_io) {
    m_path_select_proto = p_io->read_u1();
    m_path_select_metric = p_io->read_u1();
    m_congestion_control = p_io->read_u1();
    m_sync_method = p_io->read_u1();
    m_auth_protocol = p_io->read_u1();
    m_formation_info = p_io->read_u1();
    m_capability_info = p_io->read_u1();
}

