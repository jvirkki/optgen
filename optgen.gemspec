#
#  Copyright 2016 Jyri J. Virkki <jyri@virkki.com>
#
#  This file is part of optgen.
#
#  optgen is free software: you can redistribute it and/or modify it
#  under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  optgen is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with optgen.  If not, see <http://www.gnu.org/licenses/>.
#


# http://guides.rubygems.org/specification-reference/

Gem::Specification.new do |s|

  version = `cat version`
  version.chomp!

  src = File.open('bin/optgen-src', 'r')
  out = File.open('bin/optgen', 'w')
  src.each_line { |line|
    if (line =~ /VERSION = 'DEVELOPMENT'/)
      line = "$VERSION = '#{version}'\n"
    end
    out.puts line
  }
  src.close
  out.close

  s.name = 'optgen'
  s.version = version
  s.executables << 'optgen'
  s.summary = 'Generate code to parse command line options'
  s.description = 'Generate C code to parse command line options'
  s.authors = ["Jyri J. Virkki"]
  s.email = 'jyri@virkki.com'
  s.homepage = 'https://github.com/jvirkki/optgen'
  s.rubyforge_project = "nowarning"
  s.files = ["lib/liboptgen.rb"]
  s.license = 'GPLv3'
end
