<?php
abstract class Fighter
{
	abstract function fight($target);
	public function __construct($soldier)
	{
		$this->soldier_type = $soldier;
	}
	public function getType()
	{
		return ($this->soldier_type);
	}
}
 ?>