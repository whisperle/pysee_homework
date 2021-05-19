cycle = {}
cycle["name"] = "Practice2 VCR 7.2-5 part2"
cycle["components"] = [
    {
        "name": "Compressor",
        "devtype": "COMPRESSOR",
        "iPort": {"t": -10,  "x": 1, "mdot": 0.08},
        "oPort": {"t": 50},
        "ef": {}
    },
    {
        "name": "Condenser",
        "devtype": "CONDENSER",
        "iPort": {},
        "oPort": {"t": 30,  "p": 0.9},

    },
    {
        "name": "ExpansionValve",
        "devtype": "EXPANSIONVALVE",
        "iPort": {},
        "oPort": {},
    },
    {
        "name": "Evaporator",
        "devtype": "EVAPORATOR",
        "iPort": {},
        "oPort": {},
    }
]

cycle["connectors"] = [
    (("Compressor", "oPort"), ("Condenser", "iPort")),
    (("Condenser", "oPort"), ("ExpansionValve", "iPort")),
    (("ExpansionValve", "oPort"), ("Evaporator", "iPort")),
    (("Evaporator", "oPort"), ("Compressor", "iPort"))]
