{
    "targets": [
        {
            "target_name": "shadow",
            "sources": ["shadow.cc"],
            "include_dirs": ["node_modules/nan"],
            "link_settings": {
                "libraries": [
                    "-lcrypt"
                ]
            }
        }
    ]
}
