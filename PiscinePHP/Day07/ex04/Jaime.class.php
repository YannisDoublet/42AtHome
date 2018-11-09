<?php
class Jaime extends Lannister
{
	public function sleepWith( $name )
	{
		if ($name instanceof Tyrion)
			echo "Not even if I'm drunk !\n";
		if ($name instanceof Sansa)
			echo "Let's do this.\n";
		if ($name instanceof Cersei)
			echo "With pleasure, but only in a tower in Winterfell, then.\n";
	}
}
?>