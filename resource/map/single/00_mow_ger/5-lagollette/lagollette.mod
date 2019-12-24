{Modifiers
	{modifier
		{name longshot}
		{filter
			{include
				{tag
					{tag longshot}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 1.2}
			}
		}
	}
	{modifier
		{name long}
		{filter
			{include
				{tag
					{tag long}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 1.75}
			}
		}
	}
	{modifier
		{name humanshot}
		{filter
			{include
				{prop
					{prop human}
				}
			}
		}
		{parameters
			{aim_range
				{place "*"}
				{scale 1.1}
			}
		}
	}
	{modifier
		{name higharmor}
		{filter
			{include
				{tag
					{tag higharmor}
				}
			}
		}
		{parameters
			{armor
				{scale 1.2}
			}
		}
	}
	{modifier
		{name lowarmor}
		{filter
			{include
				{tag
					{tag lowarmor}
				}
			}
		}
		{parameters
			{armor
				{scale 0.9}
			}
		}
	}
}
