# This file is part of tmctl.
# Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.
# tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

# tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

mv tmctl.out /usr/local/bin/tmctl
for i in /etc/*shrc /etc/*sh/*shrc; do
    echo alias up=\'tmctl u\' >> $i
    echo alias down=\'tmctl d\' >> $i
    echo alias right=\'tmctl r\' >> $i
    echo alias left=\'tmctl l\' >> $i
    echo alias nxtln=\'tmctl n\' >> $i
    echo alias prvln=\'tmctl p\' >> $i
    echo alias setpos=\'tmctl s\' >> $i
done
