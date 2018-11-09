<?php
class Tyrion extends Lannister
{
	public function sleepWith( $name )
	{
		if ($name instanceof Jaime)
			echo "Not even if I'm drunk !\n";
		if ($name instanceof Sansa)
			echo "Let's do this.\n";
		if ($name instanceof Cersei)
			echo "Not even if I'm drunk !\n";
	}
}
?>