cycle = {}
cycle["name"] = "Practice2 VCR 7.2-5 part1"
cycle["components"] = [
    {
        "name": "Compressor",
        "devtype": "COMPRESSOR",
        "iPort": {"t": -10,  "x": 1, "mdot": 0.08},
        "oPort": {},
        "ef": 0.8
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
