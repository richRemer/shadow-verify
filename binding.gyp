{
    "targets": [
        {
            "target_name": "shadow",
            "sources": ["shadow.cc"],
            "include_dirs": ["<!(node -e 'require(\"nan\")')"],
            "link_settings": {
                "libraries": [
                    "-lcrypt"
                ]
            }
        }
    ]
}
