// This source file is part of the polarphp.org open source project
//
// Copyright (c) 2017 - 2018 polarphp software foundation
// Copyright (c) 2017 - 2018 zzu_softboy <zzu_softboy@163.com>
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://polarphp.org/LICENSE.txt for license information
// See https://polarphp.org/CONTRIBUTORS.txt for the list of polarphp project authors
//
// Created by polarboy on 2018/11/07.

#include "LitConfig.h"
#include "TestingConfig.h"
#include "formats/ShellTest.h"
#include "polarphp/basic/adt/StringRef.h"
#include "polarphp/basic/adt/Twine.h"

using polar::lit::LitConfig;
using polar::lit::TestingConfig;
using polar::lit::ShTest;
using polar::basic::StringRef;
using polar::basic::Twine;

extern "C" {
void root_cfgsetter(TestingConfig *config, LitConfig *litConfig)
{
   config->setName("shtest-shell");
   config->setSuffixes({".littest"});
   config->setTestFormat(std::make_shared<ShTest>());
   config->addSubstitution("%{check_args}", LIT_TEST_CHECKARGS_BIN);
   config->addSubstitution("%{check_path}", LIT_TEST_CHECKPATH_BIN);
   config->addSubstitution("%{write_to_stderr}", LIT_TEST_WRITE_TO_STDERR_BIN);
   config->addSubstitution("%{write_to_stdout_and_stderr}", LIT_TEST_WRITE_TO_STDOUT_AND_STDERR_BIN);
   config->addSubstitution("%{lit}", LIT_TEST_BIN);
   config->addEnvironment("PATH", Twine(POLAR_RUNTIME_OUTPUT_INTDIR, StringRef(":")).concat(std::getenv("PATH")).getStr());
}
}
